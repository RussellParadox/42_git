/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:22:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/10 19:18:56 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresegment(t_img *img, t_int2D coord1, t_int2D coord2, t_settings settings)
{
	t_int2D	pixel;
	t_int2D	diff;
	t_int2D	step;
	int	err_xy;

	pixel = coord1;
	diff.x = abs(coord1.x - coord2.x);
	diff.y = -abs(coord1.y - coord2.y);
	step = (t_int2D){.x = 1, .y = 1};
	err_xy = diff.x + diff.y;
	if (coord1.x > coord2.x)
		step.x = -1;
	if (coord1.y > coord2.y)
		step.y = -1;
	while (1)
	{
		put_pixel(img, pixel.x, pixel.y, pixel_color(coord1, \
		coord2, pixel, settings));
		if (2 * err_xy >= diff.y)
		{
			if (pixel.x == coord2.x)
				break;
			pixel.x += step.x;
			err_xy += diff.y;
		}
		if (2 * err_xy <= diff.x)
		{
			if (pixel.y == coord2.y)
				break;
			pixel.y += step.y;
			err_xy += diff.x;
		}
	}
}
