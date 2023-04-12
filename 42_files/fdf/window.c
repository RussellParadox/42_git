/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:58:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/13 00:10:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b)
		mlx_destroy_window(mlx->instance, mlx->win);
	return (0);
}

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_map(t_map *map)
{
	t_mlx		mlx;	
	t_settings	settings;
	t_img		img;

	mlx.instance = mlx_init();
	settings.max.x = 1920;
	settings.max.y = 1080;
	settings.thickness = 1.0;
	mlx.win = mlx_new_window(mlx.instance, settings.max.x, settings.max.y, "fdf");
	img.img = mlx_new_image(mlx.instance, settings.max.x, settings.max.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	map_projection(map, &img, settings);
	mlx_put_image_to_window(mlx.instance, mlx.win, img.img, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.instance);
}
