/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/04 05:47:25 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_segment(t_img *img, t_double2D coord1, t_double2D coord2, t_set settings)
{
	t_segment	segment;
	t_int2D	i;

	coord1.x = coord1.x * settings.scale + (settings.offset).x;
	coord1.y = coord1.y * settings.scale + (settings.offset).y;
	coord2.x = coord2.x * settings.scale + (settings.offset).x;
	coord2.y = coord2.y * settings.scale + (settings.offset).y;
	segment.slope_coef = (coord2.y - coord1.y) / (coord2.x - coord1.x);
	segment.intercept = coord1.y - segment.slope_coef * coord1.x;
	segment.xmax = fmax(coord1.x, coord2.x);
	segment.xmin = fmin(coord1.x, coord2.x);
	i.x = 0;
	while (i.x < settings.xmax)
	{
		i.y = 0;
		while (i.y < settings.ymax)
		{
			if (fabs(i.y - segment.slope_coef * i.x - segment.intercept) < settings.thickness && i.x <= segment.xmax && i.x >= segment.xmin)
				put_pixel(img, i.x, i.y, 0xFFFFFF);
			(i.y)++;
		}
		(i.x)++;
	}
}

t_double2D	isometric_projection(double x, double y, double z)
{
	t_double2D	proj;

	proj.x = x * (1. / sqrt(2.)) + y * (-1. / sqrt(2.)) + z * (0.);
	proj.y = x * (1. / sqrt(6.)) + y * (1 / sqrt(6.)) + z * (-sqrt(2./3.)) / 10.;
	return (proj);
}

t_int2D	new_set(int ymax)
{
	static t_int2D	i = { .x = 0, .y = 0 };
	
	if (i.y == ymax)
	{
		i.y = 0;
		(i.x)++;
	}
	else
		(i.y)++;
	return (i);
}

void	recursive_projection(t_map *map, t_img *img, t_int2D i, t_set settings)
{
	t_double2D	proj_from;
	t_double2D	proj_to;

	if (i.x > map->xmax || i.y > map->ymax)
		return ;
	proj_from = isometric_projection(i.x, i.y, (map->height)[i.y][i.x]);
	if (i.x < map->xmax)
	{
		proj_to = isometric_projection(i.x+1, i.y, (map->height)[i.y][i.x+1]);
		draw_segment(img, proj_from, proj_to, settings);
	}
	if (i.y < map->ymax)
	{
		proj_to = isometric_projection(i.x, i.y+1, (map->height)[i.y+1][i.x]);
		draw_segment(img, proj_from, proj_to, settings);
	}
	recursive_projection(map, img, new_set(map->ymax), settings);
}

void	map_projection(t_map *map, t_img *img, t_set settings)
{
	(settings.offset).x = 600;
	(settings.offset).y = 400;
	settings.scale = 40;
	recursive_projection(map, img, (t_int2D) { .x = 0, .y = 0 }, settings);
}
