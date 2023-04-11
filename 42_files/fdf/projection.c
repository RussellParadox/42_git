/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/11 23:09:23 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_double2D	isometric_projection(double x, double y, double z, int zmax)
{
	t_double2D	proj;
	double		ratio;

	proj.x = x * (1. / sqrt(2.)) + y * (-1. / sqrt(2.)) + z * (0.);
	proj.y = x * (1. / sqrt(6.)) + y * (1 / sqrt(6.)) + z * (-sqrt(2. / \
		3.)) / 10.;
	ratio = z / zmax;
	if (z < 0.5)
		proj.color = to_trgb(0, 255, 255, 255);
	else
		proj.color = to_trgb(0, 255, 51 + (int)((1. - ratio) * 180), \
			(int)(ratio * 150));
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
		(map->height)[i.y][i.x], map->zmax);
	if (i.x < map->xmax)
	{
		proj_to = isometric_projection(i.x + 1, \
			i.y, (map->height)[i.y][i.x + 1], map->zmax);
		draw_segment(img, proj_from, proj_to, settings);
	}
	if (i.y < map->ymax)
	{
		proj_to = isometric_projection(i.x, \
			i.y + 1, (map->height)[i.y + 1][i.x], map->zmax);
		draw_segment(img, proj_from, proj_to, settings);
	}
	recursive_projection(map, img, new_set(map->ymax), settings);
}

void	map_projection(t_map *map, t_img *img, t_settings settings)
{
	t_double2D	scale;
	int			proj_xmaxx;
	int			proj_ymaxx;
	int			proj_xymaxy;

	settings.border.x = settings.xmax / 15.;
	settings.border.y = settings.ymax / 15.;
	proj_xmaxx = fabs(isometric_projection(map->xmax, 0, 0, 0).x);
	proj_ymaxx = fabs(isometric_projection(0, map->ymax, 0, 0).x);
	proj_xymaxy = fabs(isometric_projection(map->xmax, map->ymax, 0, 0).y);
	scale.x = (double)(settings.xmax - 2 * settings.border.x) / \
		(proj_xmaxx + proj_ymaxx);
	scale.y = (double)(settings.ymax - 2 * settings.border.y) / \
		proj_xymaxy;
	settings.scale = fmin(scale.x, scale.y);
	settings.offset.x = settings.border.x + (settings.scale * proj_ymaxx);
	settings.offset.y = settings.border.y;
	recursive_projection(map, img, (t_int2D){.x = 0, .y = 0}, settings);
}
