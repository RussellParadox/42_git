/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:14:36 by gdornic           #+#    #+#             */
/*   Updated: 2023/05/29 16:16:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	low_segment_init(t_int2D *diff, int *diff_sign, \
	int *y_increment, int *mid_point_diff)
{
	*diff_sign = 1;
	*y_increment = 1;
	if (diff->y < 0)
	{
		*y_increment = -1;
		diff->y = -diff->y;
		if (diff->x < 0)
			*diff_sign = -1;
	}
	*mid_point_diff = 2 * diff->y - diff->x;
}

//slope coef belong to [-1, 1] for positive quadrant
//diff = difference
void	low_segment(t_img *img, t_int2D coord1, \
	t_int2D coord2, t_settings settings)
{
	t_int2D	pixel;
	t_int2D	diff;
	int		mid_point_diff;
	int		y_increment;
	int		diff_sign;

	diff.x = coord2.x - coord1.x;
	diff.y = coord2.y - coord1.y;
	low_segment_init(&diff, &diff_sign, &y_increment, &mid_point_diff);
	pixel = (t_int2D){.x = coord1.x, .y = coord1.y};
	while (pixel.x <= coord2.x)
	{
		if (pixel.x > 0 && pixel.x < settings.max.x && pixel.y > 0 && \
		pixel.y < settings.max.y)
			put_pixel(img, pixel.x, pixel.y, pixel_color(coord1, \
			coord2, pixel, settings));
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

void	high_segment_init(t_int2D *diff, int *diff_sign, \
	int *x_increment, int *mid_point_diff)
{
	*diff_sign = 1;
	*x_increment = 1;
	if (diff->x < 0)
	{
		*x_increment = -1;
		diff->y = -diff->y;
		if (diff->y < 0)
			*diff_sign = -1;
	}
	*mid_point_diff = 2 * diff->x - diff->y;
}

//slope coef belong to ]-inf, -1[ U ]1, +inf[ for positive quadrant
//diff = difference
void	high_segment(t_img *img, t_int2D coord1, \
	t_int2D coord2, t_settings settings)
{
	t_int2D	pixel;
	t_int2D	diff;
	int		mid_point_diff;
	int		x_increment;
	int		diff_sign;

	diff.x = coord2.x - coord1.x;
	diff.y = coord2.y - coord1.y;
	high_segment_init(&diff, &diff_sign, &x_increment, &mid_point_diff);
	pixel = (t_int2D){.x = coord1.x, .y = coord1.y};
	while (pixel.y <= coord2.y)
	{
		if (pixel.x > 0 && pixel.x < settings.max.x && \
		pixel.y > 0 && pixel.y < settings.max.y)
			put_pixel(img, pixel.x, pixel.y, pixel_color(coord1, \
			coord2, pixel, settings));
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

void	bresenham_segment(t_img *img, t_int2D coord1, \
	t_int2D coord2, t_settings settings)
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
