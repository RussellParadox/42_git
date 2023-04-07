/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/07 15:41:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pixel_color(t_double2D coord1, t_double2D coord2, t_int2D i, t_segment segment)
{
	int	color1;
	int	color2;
	double	ratio;

	color1 = coord1.color;
	color2 = coord2.color;
	if (color1 == color2)
		return (color1);
	ratio = hypot(i.x - coord1.x, i.y - coord1.y) / segment.dist;
	if (color1 == 0x00FFFFFF)
		color2 = to_trgb(0, 255, 255, 0);
	if (color2 == 0x00FFFFFF)
		color2 = to_trgb(0, 255, 255, 0);
	return (to_trgb(0, 255, (int)(to_g(color1) - ratio * (to_g(color1) - to_g(color2))), (int)(to_b(color1) - ratio * (to_b(color1) - to_b(color2)))));
}

void	draw_segment(t_img *img, t_double2D coord1, t_double2D coord2, \
		t_set settings)
{
	t_segment	segment;
	t_int2D		i;

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
	segment.dist = hypot(coord1.x - coord2.x, coord1.y - coord2.y);
	i.x = (int)fmax(0, segment.min.x);
	while (i.x < segment.max.x && i.x < settings.xmax)
	{
		i.y = (int)fmax(0, segment.min.y);
		while (i.y < segment.max.y && i.y < settings.ymax)
		{
			if (fabs(i.y - segment.slope_coef * i.x - \
			segment.intercept) < settings.thickness)
			{
				put_pixel(img, i.x, i.y, pixel_color(coord1, coord2, i, segment));
			}
			(i.y)++;
		}
		(i.x)++;
	}
}

t_double2D	isometric_projection(double x, double y, double z, int zmax)
{
	t_double2D	proj;
	double		ratio;

	proj.x = x * (1. / sqrt(2.)) + y * (-1. / sqrt(2.)) + z * (0.);
	proj.y = x * (1. / sqrt(6.)) + y * (1 / sqrt(6.)) + z * (-sqrt(2./3.)) / 10.;
	ratio = z / zmax;
	if (z < 0.5)
		proj.color = to_trgb(0, 255, 255, 255);
	else
		proj.color = to_trgb(0, 255, (int)((1. - ratio) * 204), (int)(ratio * 100));
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
	t_double2D	scale;
	int		proj_xmaxx;
	int		proj_ymaxx;
	int		proj_xymaxy;

	settings.border.x = settings.xmax / 15.;
	settings.border.y = settings.ymax / 15.;
	proj_xmaxx = fabs(isometric_projection(map->xmax, 0, 0, 0).x);
	proj_ymaxx = fabs(isometric_projection(0, map->ymax, 0, 0).x);
	proj_xymaxy = fabs(isometric_projection(map->xmax, map->ymax, 0, 0).y);
	scale.x = (double)(settings.xmax - 2 * settings.border.x) / (proj_xmaxx + proj_ymaxx);
	scale.y = (double)(settings.ymax - 2 * settings.border.y) / proj_xymaxy;
	settings.scale = fmin(scale.x, scale.y);
	settings.offset.x = settings.border.x + (settings.scale * proj_ymaxx);
	settings.offset.y = settings.border.y;
	recursive_projection(map, img, (t_int2D) { .x = 0, .y = 0 }, settings);
}
