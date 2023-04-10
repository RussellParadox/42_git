/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:58:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/10 14:10:42 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_map(t_map *map)
{
	t_set	settings;
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	settings.xmax = 1920;
	settings.ymax = 1080;
	mlx_win = mlx_new_window(mlx, settings.xmax, settings.ymax, "Hello world !");
	settings.thickness = 1.0;
	img.img = mlx_new_image(mlx, settings.xmax, settings.ymax);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	map_projection(map, &img, settings);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
