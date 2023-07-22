/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:22:43 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 08:25:10 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_hook(t_mlx *mlx)
{
	mlx_destroy_window(mlx->instance, mlx->win);
	mlx_loop_end(mlx->instance);
	mlx->loop_state = 0;
	return (0);
}

int	put_map_to_window(t_param *param)
{
	t_img		img;

	if (param->mlx->loop_state != 0)
	{
		img.img = mlx_new_image(param->mlx->instance, \
			param->settings->max.x, param->settings->max.y);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
		iterative_projection(param->map, &img, *(param->settings));
		mlx_put_image_to_window(param->mlx->instance, \
			param->mlx->win, img.img, 0, 0);
		mlx_destroy_image(param->mlx->instance, img.img);
	}
	return (0);
}

int	key_up_hook(int keycode, t_param *param)
{
	if (keycode == 0xff1b)
		return (destroy_hook(param->mlx));
	if (keycode == 0xffe3 || keycode == 0xffe9 || keycode == 0x70)
		param->translation = 1;
	if (keycode == 0x70)
		param->parallele = 0;
	return (0);
}

int	key_down_hook(int keycode, t_param *param)
{
	if (keycode == 0xffe3)
	{
		param->translation = 0;
		param->rotation = 1;
	}
	if (keycode == 0xffe9)
	{
		param->translation = 0;
		param->rotation = 0;
	}
	if (keycode == 0x6f)
	{
		make_scale(param->settings, param->map);
		make_offset(param->settings);
	}
	if (keycode == 0x70)
	{
		param->translation = 0;
		param->parallele = 1;
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_param *param)
{
	t_int2D	diff;
	double	scale_ratio;
	double	scale_increment;

	if (button == 1)
	{
		param->settings->cursor_to_map.x = param->settings->offset.x - x;
		param->settings->cursor_to_map.y = param->settings->offset.y - y;
	}
	if (button == 4 || button == 5)
	{
		diff.x = param->settings->offset.x - x;
		diff.y = param->settings->offset.y - y;
		if (button == 4)
			scale_increment = 10 * param->settings->scale / 100.;
		else
			scale_increment = -10 * param->settings->scale / 100.;
		param->settings->scale += scale_increment;
		scale_ratio = param->settings->scale / (param->settings->scale - \
		scale_increment);
		param->settings->offset.x = x + (diff.x) * scale_ratio;
		param->settings->offset.y = y + (diff.y) * scale_ratio;
	}
	return (0);
}
