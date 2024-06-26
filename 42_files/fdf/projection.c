/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 09:55:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	projection_color(t_int3D coord, t_map *map)
{
	double	ratio;
	int		color;

	if (map->color_profile)
	{
		if (abs(coord.z) < 0.1)
			color = to_trgb(0, 255, 255, 255);
		else if (coord.z >= 0.)
		{
			ratio = (double)coord.z / map->apex.z;
			color = to_trgb(0, 255, 51 + (int)((1. - ratio) * 180), \
				(int)(ratio * 150));
		}
		else
		{
			ratio = (double)coord.z / map->abyss.z;
			color = to_trgb(0, 51, 51 + (int)((1. - ratio) * 100), \
				100 + (int)(ratio * 150));
		}
	}
	else if (map->color[coord.x][coord.y] == -1)
		color = to_trgb(0, 255, 255, 255);
	else
		color = map->color[coord.x][coord.y];
	return (color);
}

//u is the direction vector of the straight line
t_double2D	parallele_projection(t_int3D coord, t_map *map, \
		t_base3D base, t_double3D u)
{
	t_double2D	proj;

	proj.x = (coord.x - map->center.x) * base.e1.x + \
		(coord.y - map->center.y) * base.e2.x + \
		(coord.z - map->center.z) / 10. * base.e3.x - \
		(coord.z - map->center.z) * u.x / u.z;
	proj.y = (coord.x - map->center.x) * base.e1.y + \
		(coord.y - map->center.y) * base.e2.y + \
		(coord.z - map->center.z) / 10. * base.e3.y - \
		(coord.z - map->center.z) * u.y / u.z;
	proj.color = projection_color(coord, map);
	return (proj);
}

void	iterative_projection_core(t_map *map, t_img *img, \
	t_settings settings, t_int2D i)
{
	t_int2D		proj_from;
	t_int2D		proj_to;
	t_double3D	u;

	u = settings.u;
	proj_from = scaling(parallele_projection((t_int3D){i.x, \
	i.y, map->height[i.x][i.y], 0}, map, settings.map_base, u), settings);
	if (i.x < map->max.x)
	{
		proj_to = scaling(parallele_projection((t_int3D){i.x + 1, \
		i.y, map->height[i.x + 1][i.y], 0}, map, settings.map_base, u), \
		settings);
		bresenham_segment(img, proj_from, proj_to, settings);
	}
	if (i.y < map->max.y)
	{
		proj_to = scaling(parallele_projection((t_int3D){i.x, \
		i.y + 1, map->height[i.x][i.y + 1], 0}, map, settings.map_base, u), \
		settings);
		bresenham_segment(img, proj_from, proj_to, settings);
	}
}

void	base_projection(t_img *img, t_settings settings)
{
	t_int2D			proj_from;
	t_int2D			proj_to[3];
	t_base3D		base;

	base = settings.map_base;
	proj_from = base_scaling(vector_projection((t_int3D){0, 0, 0, 0xffffff}, \
				base)); 
	proj_to[0] = base_scaling(vector_projection((t_int3D){1, 0, 0, 0xfc0303}, \
				base)); 
	proj_to[1] = base_scaling(vector_projection((t_int3D){0, 1, 0, 0x03fc0f}, \
				base)); 
	proj_to[2] = base_scaling(vector_projection((t_int3D){0, 0, 1, 0x03fcfc}, \
				base)); 
	settings.color_profile = 2;
	bresenham_segment(img, proj_from, proj_to[0], settings);
	bresenham_segment(img, proj_from, proj_to[1], settings);
	bresenham_segment(img, proj_from, proj_to[2], settings);
}

void	iterative_projection(t_map *map, t_img *img, t_settings settings)
{
	t_int2D	i;

	i.y = 0;
	while (i.y <= map->max.y)
	{
		i.x = 0;
		while (i.x <= map->max.x)
		{
			iterative_projection_core(map, img, settings, i);
			i.x++;
		}
		i.y++;
	}
	base_projection(img, settings);
}
