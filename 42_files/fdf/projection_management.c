/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 07:19:59 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_segment(t_map *map, t_img *img, t_coord2D coord1, t_coord2D coord2)

t_coord2D	isometric_projection(int x, int y, int z, t_set settings)
{
	t_coord2D	proj;

	proj.x = round((x * (-1 / sqrt(2)) + y * (1 / sqrt(2)) + z * (0)) * settings.scale) + (settings.offset).x;
	proj.y = round((x * (1 / sqrt(6)) + y * (1 / sqrt(6)) + z * (-sqrt(2/3))) * settings.scale) + (settings.offset).y;
	return (proj);
}

void	map_projection(t_map *map, t_img *img)
{
	t_set	settings;

	(settings.offset).x = min(hypot(
	recursive_projection(map, img, 0, 0, settings);
}

void	recursive_projection(t_map *map, t_img *img, int x, int y, t_set settings)
{
	t_coord2D	proj1;
	t_coord2D	proj2;
	t_coord2D	proj3;

	proj1 = isometric_projection(x, y, (map->height)[x][y], scale);
	if (x < map->xmax)
	{
		proj2 = isometric_projection(x, y, (map->height)[x+1][y], settings);
		recursive_projection(map, img, x+1, y, settings);
		draw_segment(map, img, proj1, proj2);
	}
	if (y < map->ymax)
	{
		proj3 = isometric_projection(x, y, (map->height)[x][y+1], settings);
		recursive_projection(map, img, x, y+1, settings);
		draw_segment(map, img, proj1, proj3);
	}
}
