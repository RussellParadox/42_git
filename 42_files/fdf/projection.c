/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/05/08 08:59:45 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//replace angle with base
t_double2D	isometric_projection(t_int3D coord, t_map *map, t_double3D phi, t_double3D theta)
{
	t_double2D	proj;
	double		ratio;

	proj.x = coord.x * sin(phi.x) * cos(theta.x) + coord.y * sin(phi.y) * cos(theta.y) + coord.z * sin(phi.z) * cos(theta.z);
	proj.y = coord.x * cos(phi.x) + coord.y * cos(phi.y) + coord.z * cos(phi.z);
	if (map->color_profile)
	{
		if (abs(coord.z) < 0.1)
			proj.color = to_trgb(0, 255, 255, 255);
		else if (coord.z >= 0.)
		{
			ratio = (double)coord.z / map->apex.z;
			proj.color = to_trgb(0, 255, 51 + (int)((1. - ratio) * 180), \
				(int)(ratio * 150));
		}
		else
		{
			ratio = (double)coord.z / map->abyss.z;
			proj.color = to_trgb(0, 51, 51 + (int)((1. - ratio) * 100), \
				100 + (int)(ratio * 150));
		}
	}
	else if (map->color[coord.y][coord.x] == -1)
		proj.color = to_trgb(0, 255, 255, 255);
	else
		proj.color = map->color[coord.y][coord.x];
	return (proj);
}

/*
void	reverse_iterative_projection(t_map *map, t_img *img, t_settings settings)
{
	t_int2D	proj_from;
	t_int2D	proj_to;
	t_int2D		i;

	i.y = map->max.y;
	while (i.y >= 0)
	{
		i.x = map->max.x;
		while (i.x >= 0)
		{
			proj_from = scaling(isometric_projection((t_int3D){i.x, i.y, \
				map->height[i.y][i.x]}, map), settings);
			if (i.x > 0)
			{
				proj_to = scaling(isometric_projection((t_int3D){i.x - 1, \
					i.y, map->height[i.y][i.x - 1]}, map), settings);
				bresenham_segment(img, proj_from, proj_to, settings);
			}
			if (i.y > 0)
			{
				proj_to = scaling(isometric_projection((t_int3D){i.x, \
					i.y - 1, map->height[i.y - 1][i.x]}, map), settings);
				bresenham_segment(img, proj_from, proj_to, settings);
			}
			i.x--;
		}
		i.y--;
	}
}
*/

void	iterative_projection(t_map *map, t_img *img, t_settings settings)
{
	register t_int2D	proj_from;
	register t_int2D	proj_to;
	register t_int2D		i;

	i.y = 0;
	while (i.y <= map->max.y)
	{
		i.x = 0;
		while (i.x <= map->max.x)
		{
			proj_from = scaling(isometric_projection((t_int3D){i.x, i.y, map->height[i.x][i.y]}, map, settings.phi, settings.theta), settings);
			if (i.x < map->max.x)
			{
				proj_to = scaling(isometric_projection((t_int3D){i.x + 1, i.y, map->height[i.x + 1][i.y]}, map, settings.phi, settings.theta), settings);
				bresenham_segment(img, proj_from, proj_to, settings);
			}
			if (i.y < map->max.y)
			{
				proj_to = scaling(isometric_projection((t_int3D){i.x, i.y + 1, map->height[i.x][i.y + 1]}, map, settings.phi, settings.theta), settings);
				bresenham_segment(img, proj_from, proj_to, settings);
			}
			i.x++;
		}
		i.y++;
	}
}
