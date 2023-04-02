/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 07:39:19 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_segment(t_img *img, t_double2D coord1, t_double2D coord2, t_set settings)
{
	t_int2D	round1;
	t_int2D	round2;

	round1.x = round(coord1.x * settings.scale) + (settings.offset).x;
	round1.y = round(coord1.y * settings.scale) + (settings.offset).y;
	round2.x = round(coord2.x * settings.scale) + (settings.offset).x;
	round2.y = round(coord2.y * settings.scale) + (settings.offset).y;

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

	proj1 = isometric_projection(x, y, (map->height)[x][y], scale);
	if (x < map->xmax)
	{
		proj2 = isometric_projection(x, y, (map->height)[x+1][y]);
		recursive_projection(map, img, x+1, y, settings);
		draw_segment(img, proj1, proj2, settings);
	}
	if (y < map->ymax)
	{
		proj3 = isometric_projection(x, y, (map->height)[x][y+1]);
		recursive_projection(map, img, x, y+1, settings);
		draw_segment(img, proj1, proj3, settings);
	}
}

void	map_projection(t_map *map, t_img *img, t_set settings)
{
	(settings.offset).x = 200;
	(settings.offset).y = 200;
	recursive_projection(map, img, 0, 0, settings);
}
