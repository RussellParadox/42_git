/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/12 23:02:46 by gdornic          ###   ########.fr       */
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
		ratio = z / map->zmax;
		proj.color = to_trgb(0, 255, 51 + (int)((1. - ratio) * 180), \
			(int)(ratio * 150));
	}
	else
	{
		ratio = z / map->zmin;
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

	if (i.x > map->xmax || i.y > map->ymax)
		return ;
	proj_from = isometric_projection(i.x, i.y, \
		(map->height)[i.y][i.x], map);
	if (i.x < map->xmax)
	{
		proj_to = isometric_projection(i.x + 1, \
			i.y, (map->height)[i.y][i.x + 1], map);
		draw_segment(img, proj_from, proj_to, settings);
	}
	if (i.y < map->ymax)
	{
		proj_to = isometric_projection(i.x, \
			i.y + 1, (map->height)[i.y + 1][i.x], map);
		draw_segment(img, proj_from, proj_to, settings);
	}
	recursive_projection(map, img, new_set(map->ymax), settings);
}

void	map_projection(t_map *map, t_img *img, t_settings settings)
{
	t_double2D	proj_xmax;
	t_double2D	proj_ymax;
	t_double2D	proj_xymax;

	settings.border.x = settings.xmax / 15.;
	settings.border.y = settings.ymax / 15.;
	proj_xmax = isometric_projection(map->xmax, 0, 0, map);
	proj_ymax = isometric_projection(0, map->ymax, 0, map);
	proj_xymax = isometric_projection(map->xmax, map->ymax, 0, map);
	settings.scale = fmin((double)(settings.xmax - 2 * settings.border.x) / \
		(fabs(proj_xmax.x) + fabs(proj_ymax.x)), (double)(settings.ymax - \
		2 * settings.border.y) / fabs(proj_xymax.y));
	settings.offset.x = (int)(0.5 * (settings.xmax - settings.scale * \
		proj_xymax.x));
	settings.offset.y = (int)(0.5 * (settings.ymax - settings.scale * \
		proj_xymax.y));
	recursive_projection(map, img, (t_int2D){.x = 0, .y = 0}, settings);
}
