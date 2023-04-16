/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:21:24 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/16 02:34:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	map = get_the_map(argc, argv);
	print_map(map);
	free_map(map);
	return (0);
}

/*
void	draw_circle(t_img *img, t_int2D center, int radius, int color)
{
	t_int2D	i;
	double	distance_to_center;

	i.x = center.x - radius;
	while (i.x < center.x + radius)
	{
		i.y = center.y - radius;
		while (i.y < center.y + radius)
		{
			distance_to_center = hypot(center.x - i.x, center.y - i.y);
			if (distance_to_center > radius - 5 && distance_to_center < radius)
				put_pixel(img, i.x, i.y, color);
			i.y++;
		}
		i.x++;
	}
}

int	print_thing(int x, int y, t_mlx *mlx)
{
	ft_printf("coucou");
	return (0);
}

int	render_next_frame(t_mlx *mlx)
{
	static int	color = 0x00FF0000;
	t_img	img;

	img.img = mlx_new_image(mlx->instance, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_circle(&img, (t_int2D){WIN_X / 2, WIN_Y / 2}, 300, color);
	mlx_put_image_to_window(mlx->instance, mlx->win, img.img, 0, 0);
	mlx_destroy_image(mlx->instance, img.img);
	if (color == 0x00FF0000)
		color = 0x0000FF00;
	else if (color == 0x0000FF00)
		color = 0x000000FF;
	else
		color = 0x00FF0000;
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.instance = mlx_init();
	mlx.win = mlx_new_window(mlx.instance, 1920, 1080, "fdf");
	mlx_hook(mlx.win, 6, (1L<<8), print_thing, &mlx);
	mlx_loop_hook(mlx.instance, render_next_frame, &mlx);
	mlx_loop(mlx.instance);
}
*/
