/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:58:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/15 01:40:42 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_hook(t_mlx *mlx)
{
	mlx_destroy_window(mlx->instance, mlx->win);
	mlx_loop_end(mlx->instance);
	return (0);
}

void	put_map_to_window(t_map *map, t_mlx *mlx, t_settings settings)
{
	t_img		img;

	img.img = mlx_new_image(mlx->instance, settings.max.x, settings.max.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	map_projection(map, &img, settings);
	mlx_put_image_to_window(mlx->instance, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->instance, img.img);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b)
		return (destroy_hook(mlx));
	return (0);
}

int	mouse_hook(int button, int x, int y, t_param *param)
{
	ft_printf("x=%d, y=%d\n", x, y);
	if (button == 4)
	{
		param->settings->scale = param->settings->scale + 0.2;
		put_map_to_window(param->map, param->mlx, *(param->settings));
	}
	if (button == 5)
	{
		param->settings->scale = fmax(0., param->settings->scale - 0.2);
		put_map_to_window(param->map, param->mlx, *(param->settings));
	}
	return (0);
}

int	expose_hook(t_mlx *mlx)
{
	ft_printf("coucou");
	return (0);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_mlx	*init_mlx(t_settings *settings)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->instance = mlx_init();
	mlx->win = mlx_new_window(mlx->instance, settings->max.x, settings->max.y, "fdf");
	return (mlx);
}

t_settings	*settings_init(t_double2D max, double thickness, t_map *map)
{
	t_settings	*settings;
	t_double2D	proj_xymax;
	t_double2D	proj_apex;
	t_double2D	proj_abyss;

	settings = (t_settings *)malloc(sizeof(t_settings));
	settings->max.x = max.x;
	settings->max.y = max.y;
	settings->border.x = settings->max.x / 15.;
	settings->border.y = settings->max.y / 15.;
	settings->thickness = thickness;
	settings->color_profile = map->color_profile;
	proj_xymax = isometric_projection(map->max.x, map->max.y, 0, map);
	proj_apex = isometric_projection(map->apex.x, map->apex.y, map->apex.z, map);
	proj_abyss = isometric_projection(map->abyss.x, map->abyss.y, map->abyss.z, map);
	settings->scale = fmin((double)(settings->max.x - 2 * settings->border.x) / (fabs(isometric_projection(map->max.x, 0, 0, map).x) + fabs(isometric_projection(0, map->max.y, 0, map).x)), (double)(settings->max.y - 2 * settings->border.y) / (fmax(fabs(proj_xymax.y), fabs(proj_abyss.y)) + fmax(fabs(isometric_projection(0, 0, 0, map).y), fabs(proj_apex.y))));
	settings->offset.x = (int)(0.5 * (settings->max.x - settings->scale * \
		isometric_projection(map->max.x, map->max.y, map->apex.z, map).x));
	settings->offset.y = (int)(0.5 * (settings->max.y - settings->scale * \
		isometric_projection(map->max.x, map->max.y, map->apex.z, map).y));
	return (settings);
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
	t_param		*hook_param;

	hook_param = (t_param *)malloc(sizeof(t_param));
	hook_param->settings = settings_init((t_double2D){.x=1920, .y=1080}, 1.0, map);
	hook_param->mlx = init_mlx(hook_param->settings);
	hook_param->map = map;
	put_map_to_window(map, hook_param->mlx, *(hook_param->settings));
	mlx_key_hook(hook_param->mlx->win, key_hook, hook_param->mlx);
	mlx_mouse_hook(hook_param->mlx->win, mouse_hook, hook_param);
	mlx_hook(hook_param->mlx->win, 17, 0L, destroy_hook, hook_param->mlx);
	mlx_loop(hook_param->mlx->instance);
	free_param(hook_param);
	return (0);
}
