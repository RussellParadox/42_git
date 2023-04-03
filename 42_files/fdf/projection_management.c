/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 21:13:32 by gdornic          ###   ########.fr       */
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
				put_pixel(img, i.x, i.y, 0xFF0000);
			(i.y)++;
		}
		(i.x)++;
	}
}

t_double2D	isometric_projection(int x, int y, int z)
{
	t_double2D	proj;

	proj.x = x * (-1 / sqrt(2)) + y * (1 / sqrt(2)) + z * (0);
	proj.y = x * (1 / sqrt(6)) + y * (1 / sqrt(6)) + z * (-sqrt(2/3));
	return (proj);
}

void	recursive_projection(t_map *map, t_img *img, int x, int y, t_set settings)
{
	t_double2D	proj1;
	t_double2D	proj2;
	t_double2D	proj3;

	proj1 = isometric_projection(x, y, (map->height)[x][y]);
	if (x < map->xmax)
	{
		proj2 = isometric_projection(x, y, (map->height)[x+1][y]);
		draw_segment(img, proj1, proj2, settings);
	}
	if (y < map->ymax)
	{
		proj3 = isometric_projection(x, y, (map->height)[x][y+1]);
		draw_segment(img, proj1, proj3, settings);
	}
	if (x < map->xmax && y < map->ymax)
		recursive_projection(map, img, x+1, y, settings);
}

void	map_projection(t_map *map, t_img *img, t_set settings)
{
	(settings.offset).x = 200;
	(settings.offset).y = 200;
	settings.scale = fmin(i
	recursive_projection(map, img, 0, 0, settings);
}
