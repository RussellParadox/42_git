/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:14:36 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/17 15:23:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pixel_color(t_int2D coord1, t_double2D coord2, t_int2D i, \
		t_settings settings)
{
	int			color1;
	int			color2;
	double		ratio;

	color1 = coord1.color;
	color2 = coord2.color;
	if (color1 == color2)
		return (color1);
	ratio = hypot(i.x - coord1.x, i.y - coord1.y) / settings.dist;
	if (settings.color_profile)
	{	
		if (color1 == 0x00FFFFFF)
			color1 = to_trgb(0, 255, 255, 0);
		if (color2 == 0x00FFFFFF)
			color2 = to_trgb(0, 255, 255, 0);
	}
	return (to_trgb(0, (int)(to_r(color1) - ratio * (to_r(color1) - to_r(color2))), (int)(to_g(color1) - ratio * (to_g(color1) - to_g(color2))), (int)(to_b(color1) - ratio * (to_b(color1) - to_b(color2)))));
}
/*
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
*/
t_int2D	scaling(t_double2D double_coord, t_settings settings)
{
	t_int2D	int_coord;

	double_coord.x = double_coord.x * settings.scale + settings.offset.x;
	double_coord.y = double_coord.y * settings.scale + settings.offset.y;
	int_coord.x = (int)round(double_coord.x);
	int_coord.y = (int)round(double_coord.y);
	if (int_coord.x < 0)
		int_coord.x = 0;
	if (int_coord.y < 0)
		int_coord.y = 0;
	if (int_coord.x > settings.max.x)
		int_coord.x = settings.max.x;
	if (int_coord.y > settings.max.y)
		int_coord.y = settings.max.y;
	return (int_coord);
}

//slope coef belong to [-1, 1] for positive quadrant
//diff = difference
void	low_segment(t_img *img, t_int2D coord1, t_int2D coord2, t_settings settings)
{
	t_int2D	pixel;
	t_int2D	diff;
	int	mid_point_diff;
	int	y_increment;
	int	diff_sign;

	diff.x = coord2.x - coord1.x;
	diff.y = coord2.y - coord1.y;
	diff_sign = 1;
	y_increment = 1;
	if (diff.y < 0)
	{
		y_increment = -1;
		diff.y = -diff.y;
		if (diff.x < 0)
			diff_sign = -1;
	}
	mid_point_diff = 2 * diff.y - diff.x;
	pixel.y = coord1.y;
	pixel.x = coord1.x;
	while (pixel.x <= coord2.x)
	{
		put_pixel(img, pixel.x, pixel.y, 0x00FFFFFF);
		if (diff_sign * mid_point_diff > 0)
		{
			pixel.y += y_increment;
			mid_point_diff += 2 * (diff.y - diff.x);
		}
		else
			mid_point_diff += 2 * diff.y;
		pixel.x++;
	}
}

//slope coef belong to ]-inf, -1[ U ]1, +inf[ for positive quadrant
//diff = difference
void	high_segment(t_img *img, t_int2D coord1, t_int2D coord2, t_settings settings)
{
	t_int2D	pixel;
	t_int2D	diff;
	int	mid_point_diff;
	int	x_increment;
	int	diff_sign;

	diff.x = coord2.x - coord1.x;
	diff.y = coord2.y - coord1.y;
	diff_sign = 1;
	x_increment = 1;
	if (diff.x < 0)
	{
		x_increment = -1;
		diff.y = -diff.y;
		if (diff.y < 0)
			diff_sign = -1;
	}
	mid_point_diff = 2 * diff.x - diff.y;
	pixel.x = coord1.x;
	pixel.y = coord1.y;
	while (pixel.y <= coord2.y)
	{
		put_pixel(img, pixel.x, pixel.y, 0x00FFFFFF);
		if (diff_sign * mid_point_diff > 0)
		{
			pixel.x += x_increment;
			mid_point_diff += 2 * (diff.x - diff.y);
		}
		else
			mid_point_diff += 2 * diff.x;
		pixel.y++;
	}
}

void	bresenham_segment(t_img *img, t_int2D coord1, t_int2D coord2, t_settings settings)
{
	if (abs(coord1.y - coord2.y) < abs(coord1.x - coord2.x))
	{
		if (coord1.x > coord2.x)
			low_segment(img, coord2, coord1, settings);
		else
			low_segment(img, coord1, coord2, settings);
	}
	else
	{
		if (coord1.y > coord2.y)
			high_segment(img, coord2, coord1, settings);
		else
			high_segment(img, coord1, coord2, settings);
	}
}
