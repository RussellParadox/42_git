/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:58:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/21 22:37:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_hook(t_mlx *mlx)
{
	mlx_destroy_window(mlx->instance, mlx->win);
	mlx_loop_end(mlx->instance);
	return (0);
}

int	put_map_to_window(t_param *param)
{
	t_img		img;

	img.img = mlx_new_image(param->mlx->instance, param->settings->max.x, param->settings->max.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	map_projection(param->map, &img, *(param->settings));
	mlx_put_image_to_window(param->mlx->instance, param->mlx->win, img.img, 0, 0);
	mlx_destroy_image(param->mlx->instance, img.img);
	return (0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b)
		return (destroy_hook(mlx));
	return (0);
}

int	mouse_hook(int button, int x, int y, t_param *param)
{
	t_int2D	diff;
	double	scale_ratio;

	if (button == 1)
	{
		param->settings->cursor_to_map.x = param->settings->offset.x - x;
		param->settings->cursor_to_map.y = param->settings->offset.y - y;
	}
	if (button == 4)
	{
		param->settings->scale += 10;
		diff.x = param->settings->offset.x - x;
		diff.y = param->settings->offset.y - y;
		scale_ratio = param->settings->scale / (param->settings->scale - 10);
		param->settings->offset.x = x + (diff.x) * scale_ratio;
		param->settings->offset.y = y + (diff.y) * scale_ratio;
		put_map_to_window(param);
	}
	if (button == 5)
	{
		param->settings->scale = fmax(0.1, param->settings->scale - 10);
		diff.x = param->settings->offset.x - x;
		diff.y = param->settings->offset.y - y;
		scale_ratio = param->settings->scale / (param->settings->scale + 10);
		param->settings->offset.x = x + (diff.x) * scale_ratio;
		param->settings->offset.y = y + (diff.y) * scale_ratio;
		put_map_to_window(param);
	}
	return (0);
}

int	mouse_translation(int x, int y, t_param *param)
{
	static t_int2D	previous;

	if (hypot(previous.x - x, previous.y - y) > 3)
	{
		param->settings->offset.x = x + param->settings->cursor_to_map.x;
		param->settings->offset.y = y + param->settings->cursor_to_map.y;
		put_map_to_window(param);
	}
	previous.x = x;
	previous.y = y;
	return (0);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	free_param(t_param *param)
{
	free(param->mlx->instance);
	free(param->settings);
	free(param->mlx);
	free(param);
}

int	print_map(t_map *map)
{
	t_param		*param;

	param = (t_param *)malloc(sizeof(t_param));
	param->settings = settings_init((t_double2D){.x=WIN_X, .y=WIN_Y}, 1.0, map);
	param->mlx = init_mlx(param->settings);
	param->map = map;
	put_map_to_window(param);
	mlx_key_hook(param->mlx->win, key_hook, param->mlx);
	mlx_mouse_hook(param->mlx->win, mouse_hook, param);
	mlx_hook(param->mlx->win, 6, (1L<<8), mouse_translation, param);
	mlx_hook(param->mlx->win, 17, 0L, destroy_hook, param->mlx);
	mlx_loop(param->mlx->instance);
	free_param(param);
	return (0);
}
