/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:58:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/04 05:48:14 by gdornic          ###   ########.fr       */
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
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world !");
	settings.xmax = 1920;
	settings.ymax = 1080;
	settings.thickness = 1.0;
	//(settings.offset).x = 200;
	//(settings.offset).y = 200;
	//settings.scale = 100;
	img.img = mlx_new_image(mlx, settings.xmax, settings.ymax);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//draw_segment(&img, (t_double2D) { .x = isometric_projection(0,0,0).x, .y = isometric_projection(0,0,0).y }, (t_double2D) { .x = isometric_projection(1,0,0).x, .y = isometric_projection(1,0,0).y }, settings);
	map_projection(map, &img, settings);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
