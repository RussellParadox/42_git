/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:31:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 01:57:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <stdio.h>

double	ft_abs(double x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

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
				mlx_pixel_put(mlx, mlx_win, i, j, 0x00FF00);
			j++;
		}
		i++;
	}
}

void	draw_segment(void *mlx, void *mlx_win, int x1, int y1, int x2, int y2)
{
	int	i;
	int	j;
	int	intercept;
	double	slope_coef;

	slope_coef = (double)(y2 - y1) / (x2 - x1);
	intercept = y1 - slope_coef * x1;
	i = 0;
	while (i < 1920)
	{
		j = 0;
		while (j < 1080)
		{
			if (ft_abs(j - slope_coef * i - intercept) < 1.0 && j <= ft_max(x2, x1) && j >= ft_min(x2, x1) && i <= ft_max(x2, x1) && i >= ft_min(x2, x1))
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
	char	*msg;

	msg = (char *)malloc(10 * sizeof(char));
	msg[0] = 'a';
	msg[1] = '\0';
	ft_printf("%s\n", msg);
	ft_putstr_fd("Initiating the window\n", 1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	draw_segment(mlx, mlx_win, 200, 400, 800, 300);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
}
