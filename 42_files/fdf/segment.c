/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:14:36 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/16 03:23:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pixel_color(t_double2D coord1, t_double2D coord2, t_int2D i, \
		t_segment segment)
{
	int			color1;
	int			color2;
	double		ratio;

	color1 = coord1.color;
	color2 = coord2.color;
	if (color1 == color2)
		return (color1);
	ratio = hypot(i.x - coord1.x, i.y - coord1.y) / segment.dist;
	if (segment.color_profile)
	{	
		if (color1 == 0x00FFFFFF)
			color1 = to_trgb(0, 255, 255, 0);
		if (color2 == 0x00FFFFFF)
			color2 = to_trgb(0, 255, 255, 0);
	}
	return (to_trgb(0, (int)(to_r(color1) - ratio * (to_r(color1) - to_r(color2))), (int)(to_g(color1) - ratio * (to_g(color1) - to_g(color2))), (int)(to_b(color1) - ratio * (to_b(color1) - to_b(color2)))));
}

t_segment	segment_init(t_double2D coord1, t_double2D coord2, int color_profile)
{
	t_segment	segment;

	segment.coef.x = coord2.y - coord1.y;
	segment.coef.y = coord1.x - coord2.x;
	segment.max.x = (int)ceil(fmax(coord1.x, coord2.x));
	segment.min.x = (int)ceil(fmin(coord1.x, coord2.x));
	segment.max.y = (int)ceil(fmax(coord1.y, coord2.y));
	segment.min.y = (int)ceil(fmin(coord1.y, coord2.y));
	segment.dist = hypot(coord1.x - coord2.x, coord1.y - coord2.y);
	segment.color_profile = color_profile;
	return (segment);
}

void	draw_segment(t_img *img, t_double2D coord1, t_double2D coord2, \
		t_settings settings)
{
	t_segment	segment;
	t_int2D		i;

	coord1.x = coord1.x * settings.scale + settings.offset.x;
	coord1.y = coord1.y * settings.scale + settings.offset.y;
	coord2.x = coord2.x * settings.scale + settings.offset.x;
	coord2.y = coord2.y * settings.scale + settings.offset.y;
	segment = segment_init(coord1, coord2, settings.color_profile);
	i.x = (int)fmax(0, segment.min.x);
	while (i.x < segment.max.x && i.x < settings.max.x)
	{
		i.y = (int)fmax(0, segment.min.y);
		while (i.y < segment.max.y && i.y < settings.max.y)
		{
			if (fabs((segment.coef.x * (i.x - coord1.x) + \
				segment.coef.y * (i.y - coord1.y))) < settings.thickness \
				* fmax(fabs(segment.coef.y), fabs(segment.coef.x)))
			{
				put_pixel(img, i.x, i.y, \
					pixel_color(coord1, coord2, i, segment));
			}
			(i.y)++;
		}
		(i.x)++;
	}
}

t_int2D	double_to_int2D(t_double2D double_coord, t_settings settings)
{
	t_int2D	int_coord;

	double_coord.x = double_coord.x * settings.scale + settings.offset.x;
	double_coord.y = double_coord.y * settings.scale + settings.offset.y;
	int_coord.x = (int)(double_coord.x);
	int_coord.y = (int)(double_coord.y);
	return (int_coord);
}

void	bresenham_segment(t_img *img, t_int2D coord1, t_int2D coord2, t_settings settings)
{
	t_int2D		pixel;
	t_int2D		diff;
	int		error;
	t_int2D		increment;

	diff.y = coord2.y - coord1.y;
	diff.x = coord2.x - coord1.x;
	pixel.y = coord1.y;
	pixel.x = coord1.x;
	increment.x = diff.y * 2;
	increment.y = -diff.x * 2;
	while (pixel.x <= coord2.x)
	{
		put_pixel(img, pixel.x, pixel.y, 0x00FFFFFF);
		error += increment.x;
		if (error <= 0)
		{
			pixel.y++;
			error += increment.y;
		}
		pixel.x++;
	}
}
