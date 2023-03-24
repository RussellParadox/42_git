/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:31:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/24 02:44:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	draw_circle(void *mlx, void *mlx_win, int x, int y, int r)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r)
				mlx_pixel_put(mlx, mlx_win, i, j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_rectangle(void *mlx, void *mlx_win, int x, int y, int len1, int len2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			if ((i >= x && i < x + len1) && (j >= y && j < y + len2))
				mlx_pixel_put(mlx, mlx_win, i, j, 0xFF0000);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	draw_circle(mlx, mlx_win, 200 + 200, 1080 / 2 - 200, 200);
	draw_circle(mlx, mlx_win, 200 + 200, 1080 / 2 + 200, 200);
	draw_rectangle(mlx, mlx_win, 200 + 200, 1080 / 2 - 200, 800, 400);
	draw_circle(mlx, mlx_win, 400 + 800, 1080 / 2, 200);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
}
