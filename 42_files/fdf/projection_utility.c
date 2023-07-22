/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:01:57 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 10:02:29 by gdornic          ###   ########.fr       */
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
	if (settings.color_profile == 2)
	{
		if (color1 == 0xffffff)
			return (color2);
		return (color1);
	}
	ratio = hypot(i.x - coord1.x, i.y - coord1.y) / settings.dist;
	if (settings.color_profile)
	{
		if (color1 == 0x00FFFFFF)
			color1 = to_trgb(0, 255, 255, 0);
		if (color2 == 0x00FFFFFF)
			color2 = to_trgb(0, 255, 255, 0);
	}
	return (to_trgb(0, (int)(to_r(color1) - ratio * (to_r(color1) - \
	to_r(color2))), (int)(to_g(color1) - ratio * (to_g(color1) - \
	to_g(color2))), (int)(to_b(color1) - ratio * (to_b(color1) - \
	to_b(color2)))));
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

t_int2D	base_scaling(t_double2D double_coord)
{
	t_int2D	int_coord;
	double	scale;

	scale = 70;
	double_coord.x = double_coord.x * scale + WIN_X * 9 / 10.;
	double_coord.y = double_coord.y * scale + WIN_Y * 9 / 10.;
	int_coord.x = (int)round(double_coord.x);
	int_coord.y = (int)round(double_coord.y);
	int_coord.color = double_coord.color;
	return (int_coord);
}
