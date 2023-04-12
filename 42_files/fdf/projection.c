/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/13 00:37:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_double2D	isometric_projection(double x, double y, double z, t_map *map)
{
	t_double2D	proj;
	double		ratio;

	proj.x = x * (1. / sqrt(2.)) + y * (-1. / sqrt(2.)) + z * (0.);
	proj.y = x * (1. / sqrt(6.)) + y * (1 / sqrt(6.)) + z * (-sqrt(2. / \
		3.));
	if (fabs(z) < 0.1)
		proj.color = to_trgb(0, 255, 255, 255);
	else if (z >= 0.)
	{
		ratio = z / map->apex.z;
		proj.color = to_trgb(0, 255, 51 + (int)((1. - ratio) * 180), \
			(int)(ratio * 150));
	}
	else
	{
		ratio = z / map->abyss.z;
		proj.color = to_trgb(0, 51, 51 + (int)((1. - ratio) * 100), \
			100 + (int)(ratio * 150));
	}
	return (proj);
}

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

void	map_projection(t_map *map, t_img *img, t_settings settings)
{
	t_double2D	proj_xymax;
	t_double2D	proj_apex;
	t_double2D	proj_abyss;

	settings.border.x = settings.max.x / 15.;
	settings.border.y = settings.max.y / 15.;
	proj_xymax = isometric_projection(map->max.x, map->max.y, 0, map);
	proj_apex = isometric_projection(map->apex.x, map->apex.y, map->apex.z, map);
	proj_abyss = isometric_projection(map->abyss.x, map->abyss.y, map->abyss.z, map);
	settings.scale = fmin((double)(settings.max.x - 2 * settings.border.x) / (fabs(isometric_projection(map->max.x, 0, 0, map).x) + fabs(isometric_projection(0, map->max.y, 0, map).x)), (double)(settings.max.y - 2 * settings.border.y) / (fmax(fabs(proj_xymax.y), fabs(proj_abyss.y)) + fmax(fabs(isometric_projection(0, 0, 0, map).y), fabs(proj_apex.y))));
	settings.offset.x = (int)(0.5 * (settings.max.x - settings.scale * \
		isometric_projection(map->max.x, map->max.y, map->apex.z, map).x));
	settings.offset.y = (int)(0.5 * (settings.max.y - settings.scale * \
		isometric_projection(map->max.x, map->max.y, map->apex.z, map).y));
	recursive_projection(map, img, (t_int2D){.x = 0, .y = 0}, settings);
}
