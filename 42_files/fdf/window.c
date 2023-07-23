/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:58:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 00:15:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mouse_rotation(t_param *param, t_double2D v, double magnitude)
{
	t_double3D	u;

	if (param->rotation)
	{
		u.x = -v.y / magnitude;
		u.y = v.x / magnitude;
		u.z = 0;
	}
	else
	{
		u.x = 0;
		u.y = 0;
		u.z = signof(v.x);
	}
	base_rotation(&(param->settings->map_base), u, M_PI / 240);
}

int	mouse_transformation(int x, int y, t_param *param)
{
	static t_int2D	previous;
	t_double2D		v;
	double			magnitude;

	v.x = previous.x - x;
	v.y = previous.y - y;
	magnitude = hypot(v.x, v.y);
	if (magnitude > 2)
	{
		if (param->translation)
		{
			param->settings->offset.x = x + param->settings->cursor_to_map.x;
			param->settings->offset.y = y + param->settings->cursor_to_map.y;
		}
		else if (param->parallele)
		{
			param->settings->u.x += v.x / magnitude / 100.;
			param->settings->u.y += v.y / magnitude / 100.;
		}
		else
			mouse_rotation(param, v, magnitude);
	}
	previous.x = x;
	previous.y = y;
	return (0);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	register char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	free_param(t_param *param)
{
	mlx_destroy_display(param->mlx->instance);
	free(param->mlx->instance);
	free(param->settings);
	free(param->mlx);
	free(param);
}

int	print_map(t_map *map)
{
	t_param		*param;

	param = (t_param *)malloc(sizeof(t_param));
	param->settings = settings_init((t_double2D){WIN_X, WIN_Y, 0}, map);
	param->mlx = init_mlx(param->settings);
	param->map = map;
	param->translation = 1;
	param->rotation = 1;
	param->mlx->loop_state = 1;
	param->parallele = 0;
	mlx_hook(param->mlx->win, 2, (1L << 0), key_down_hook, param);
	mlx_mouse_hook(param->mlx->win, mouse_hook, param);
	mlx_hook(param->mlx->win, 6, (1L << 8), mouse_transformation, param);
	mlx_key_hook(param->mlx->win, key_up_hook, param);
	mlx_hook(param->mlx->win, 17, 0L, destroy_hook, param->mlx);
	mlx_loop_hook(param->mlx->instance, put_map_to_window, param);
	mlx_loop(param->mlx->instance);
	free_param(param);
	return (0);
}
