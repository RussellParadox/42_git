/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/05 01:45:35 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_segment(t_img *img, t_double2D coord1, t_double2D coord2, \
		t_set settings)
{
	t_segment	segment;
	t_int2D		i;
	double		ratio;

	coord1.x = coord1.x * settings.scale + settings.offset.x;
	coord1.y = coord1.y * settings.scale + settings.offset.y;
	coord2.x = coord2.x * settings.scale + settings.offset.x;
	coord2.y = coord2.y * settings.scale + settings.offset.y;
	segment.slope_coef = (coord2.y - coord1.y) / (coord2.x - coord1.x);
	segment.intercept = coord1.y - segment.slope_coef * coord1.x;
	segment.max.x = (int)ceil(fmax(coord1.x, coord2.x));
	segment.min.x = (int)ceil(fmin(coord1.x, coord2.x));
	segment.max.y = (int)ceil(fmax(coord1.y, coord2.y));
	segment.min.y = (int)ceil(fmin(coord1.y, coord2.y));
	i.x = segment.min.x;
	while (i.x < segment.max.x)
	{
		i.y = segment.min.y;
		while (i.y < segment.max.y)
		{
			if (fabs(i.y - segment.slope_coef * i.x - \
			segment.intercept) < settings.thickness)
			{
				ratio = (double)i.y / (double)segment.max.y;
				put_pixel(img, i.x, i.y, 0x00FFFFFF);
			}
			(i.y)++;
		}
		(i.x)++;
	}
}

t_double2D	isometric_projection(double x, double y, double z, int zmax)
{
	t_double2D	proj;

	proj.x = x * (1. / sqrt(2.)) + y * (-1. / sqrt(2.)) + z * (0.);
	proj.y = x * (1. / sqrt(6.)) + y * (1 / sqrt(6.)) + z * (-sqrt(2./3.)) / 10.;
	if (z < 0.5)
		proj.color = to_trgb(0, 255, 255, 255);
	else if (zmax - z < 0.5)
		proj.color = to_trgb(0, 100, 0, 255);
	else
		proj.color = to_trgb(0, (int)(z / zmax * 255), (int)((1 - z / zmax) * 255), 0);
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
	proj_from = isometric_projection(i.x, i.y, (map->height)[i.y][i.x], map->zmax);
	if (i.x < map->xmax)
	{
		proj_to = isometric_projection(i.x+1, i.y, (map->height)[i.y][i.x+1], map->zmax);
		draw_segment(img, proj_from, proj_to, settings);
	}
	if (i.y < map->ymax)
	{
		proj_to = isometric_projection(i.x, i.y+1, (map->height)[i.y+1][i.x], map->zmax);
		draw_segment(img, proj_from, proj_to, settings);
	}
	recursive_projection(map, img, new_set(map->ymax), settings);
}

void	map_projection(t_map *map, t_img *img, t_set settings)
{
	(settings.offset).x = 600;
	(settings.offset).y = 400;
	settings.scale = 50;
	recursive_projection(map, img, (t_int2D) { .x = 0, .y = 0 }, settings);
}
