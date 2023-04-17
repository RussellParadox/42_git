/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:21:24 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/17 19:38:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int	main(int argc, char *argv[])
{
	t_map	*map;

	map = get_the_map(argc, argv);
	print_map(map);
	free_map(map);
	return (0);
}

//slope coef belong to [-1, 1] for positive quadrant
//diff = difference
void	low_segment(t_img *img, t_int2D coord1, t_int2D coord2)
{
	t_int2D	pixel;
	t_int2D	diff;
	int	mid_point_diff;
	int	y_increment;
	int	diff_sign;

	diff.x = coord2.x - coord1.x;
	diff.y = coord2.y - coord1.y;
	diff_sign = 1;
	y_increment = 1;
	if (diff.y < 0)
	{
		y_increment = -1;
		diff.y = -diff.y;
		if (diff.x < 0)
			diff_sign = -1;
	}
	mid_point_diff = 2 * diff.y - diff.x;
	pixel.y = coord1.y;
	pixel.x = coord1.x;
	while (pixel.x <= coord2.x)
	{
		put_pixel(img, pixel.x, pixel.y, 0x00FFFFFF);
		if (diff_sign * mid_point_diff > 0)
		{
			pixel.y += y_increment;
			mid_point_diff += 2 * (diff.y - diff.x);
		}
		else
			mid_point_diff += 2 * diff.y;
		pixel.x++;
	}
}

//slope coef belong to ]-inf, -1[ U ]1, +inf[ for positive quadrant
//diff = difference
void	high_segment(t_img *img, t_int2D coord1, t_int2D coord2)
{
	t_int2D	pixel;
	t_int2D	diff;
	int	mid_point_diff;
	int	x_increment;
	int	diff_sign;

	diff.x = coord2.x - coord1.x;
	diff.y = coord2.y - coord1.y;
	diff_sign = 1;
	x_increment = 1;
	if (diff.x < 0)
	{
		x_increment = -1;
		diff.y = -diff.y;
		if (diff.y < 0)
			diff_sign = -1;
	}
	mid_point_diff = 2 * diff.x - diff.y;
	pixel.x = coord1.x;
	pixel.y = coord1.y;
	while (pixel.y <= coord2.y)
	{
		put_pixel(img, pixel.x, pixel.y, 0x00FFFFFF);
		if (diff_sign * mid_point_diff > 0)
		{
			pixel.x += x_increment;
			mid_point_diff += 2 * (diff.x - diff.y);
		}
		else
			mid_point_diff += 2 * diff.x;
		pixel.y++;
	}
}

void	bresenham_segment(t_img *img, t_int2D coord1, t_int2D coord2)
{
	if (abs(coord1.y - coord2.y) < abs(coord1.x - coord2.x))
	{
		if (coord1.x > coord2.x)
			low_segment(img, coord2, coord1);
		else
			low_segment(img, coord1, coord2);
	}
	else
	{
		if (coord1.y > coord2.y)
			high_segment(img, coord2, coord1);
		else
			high_segment(img, coord1, coord2);
	}
}
*/

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

int	mouse_thing(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
		ft_printf("x:%d,y:%d\n", x, y);
	return (0);
}

int	print_thing(int x, int y, t_mlx *mlx)
{
	ft_printf("x:%d,y:%d\n", x, y);
	return (0);
}

int	render_next_frame(t_mlx *mlx)
{
	static int	color = 0x00FF0000;
	static int	count;
	t_img	img;

	img.img = mlx_new_image(mlx->instance, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_circle(&img, (t_int2D){WIN_X / 2, WIN_Y / 2}, 300, color);
	//bresenham_segment(&img, (t_int2D){300,300}, (t_int2D){100,50});
	mlx_put_image_to_window(mlx->instance, mlx->win, img.img, 0, 0);
	ft_printf("render count:%d\n", count++);
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
	mlx_mouse_hook(mlx.win, mouse_thing, &mlx);
	mlx_loop_hook(mlx.instance, render_next_frame, &mlx);
	mlx_loop(mlx.instance);
}
