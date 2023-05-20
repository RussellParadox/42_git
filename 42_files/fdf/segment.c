/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:14:36 by gdornic           #+#    #+#             */
/*   Updated: 2023/05/20 12:52:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	pixel_color(t_int2D coord1, t_int2D coord2, t_int2D i, \
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

t_int2D	scaling(t_double2D double_coord, t_settings settings)
{
	t_int2D	int_coord;

	double_coord.x = double_coord.x * settings.scale + settings.offset.x;
	double_coord.y = double_coord.y * settings.scale + settings.offset.y;
	int_coord.x = (int)round(double_coord.x);
	int_coord.y = (int)round(double_coord.y);
	int_coord.color = double_coord.color;
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
		if (pixel.x > 0 && pixel.x < settings.max.x && pixel.y > 0 && pixel.y < settings.max.y)
			put_pixel(img, pixel.x, pixel.y, pixel_color(coord1, coord2, pixel, settings));
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
		if (pixel.x > 0 && pixel.x < settings.max.x && pixel.y > 0 && pixel.y < settings.max.y)
			put_pixel(img, pixel.x, pixel.y, pixel_color(coord1, coord2, pixel, settings));
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
	t_int2D	diff;

	diff.x = coord2.x - coord1.x;
	diff.y = coord2.y - coord1.y;
	settings.dist = hypot(diff.x, diff.y);
	if (abs(diff.y) < abs(diff.x))
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
