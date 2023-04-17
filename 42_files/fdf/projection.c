/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/17 15:19:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_double2D	isometric_projection(t_int3D coord, t_map *map)
{
	t_double2D	proj;
	double		ratio;

	proj.x = coord.x * (1. / sqrt(2.)) + coord.y * (-1. / sqrt(2.));
	proj.y = coord.x * (1. / sqrt(6.)) + coord.y * (1 / sqrt(6.)) + coord.z * (-sqrt(2. / \
		3.));
	if (map->color_profile)
	{
		if (abs(coord.z) < 0.1)
			proj.color = to_trgb(0, 255, 255, 255);
		else if (coord.z >= 0.)
		{
			ratio = coord.z / map->apex.z;
			proj.color = to_trgb(0, 255, 51 + (int)((1. - ratio) * 180), \
				(int)(ratio * 150));
		}
		else
		{
			ratio = coord.z / map->abyss.z;
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

//deprecated
/*
t_int2D	new_set(int ymax)
{
	static t_int2D	i = {.x = 0, .y = 0};

	if (i.y == ymax)
	{
		i.y = 0;
		(i.x)++;
	}
	else
		(i.y)++;
	return (i);
}

void	recursive_projection(t_map *map, t_img *img, t_int2D i, \
		t_settings settings)
{
	t_double2D	proj_from;
	t_double2D	proj_to;

	if (i.x > map->max.x || i.y > map->max.y)
		return ;
	proj_from = isometric_projection(i.x, i.y, \
		(map->height)[i.y][i.x], map);
	if (i.x < map->max.x)
	{
		proj_to = isometric_projection(i.x + 1, \
			i.y, (map->height)[i.y][i.x + 1], map);
		draw_segment(img, proj_from, proj_to, settings);
	}
	if (i.y < map->max.y)
	{
		proj_to = isometric_projection(i.x, \
			i.y + 1, (map->height)[i.y + 1][i.x], map);
		draw_segment(img, proj_from, proj_to, settings);
	}
	recursive_projection(map, img, new_set(map->max.y), settings);
}
*/

void	iterative_projection(t_map *map, t_img *img, t_settings settings)
{
	t_int2D	proj_from;
	t_int2D	proj_to;
	t_int2D		i;

	i.y = 0;
	while (i.y <= map->max.y)
	{
		i.x = 0;
		while (i.x <= map->max.x)
		{
			proj_from = scaling(isometric_projection((t_int3D){i.x, i.y, \
				map->height[i.y][i.x]}, map), settings);
			if (i.x < map->max.x)
			{
				proj_to = scaling(isometric_projection((t_int3D){i.x + 1, \
					i.y, map->height[i.y][i.x + 1]}, map), settings);
				//draw_segment(img, proj_from, proj_to, settings);
				bresenham_segment(img, proj_from, proj_to, settings);
			}
			if (i.y < map->max.y)
			{
				proj_to = scaling(isometric_projection((t_int3D){i.x, \
					i.y + 1, map->height[i.y + 1][i.x]}, map), settings);
				//draw_segment(img, proj_from, proj_to, settings);
				bresenham_segment(img, proj_from, proj_to, settings);
			}
			i.x++;
		}
		i.y++;
	}
}

void	map_projection(t_map *map, t_img *img, t_settings settings)
{
	//recursive_projection(map, img, (t_int2D){.x = 0, .y = 0}, settings);
	iterative_projection(map, img, settings);
}
