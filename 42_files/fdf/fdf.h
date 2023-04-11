/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:00:43 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/11 14:45:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <libft.h>
# include <get_next_line.h>
# include <libftprintf.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_map
{
	int	**height;
	int	xmax;
	int	ymax;
	int	zmax;
}	t_map;

typedef struct s_mlx
{
	void	*instance;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_double2D
{
	double	x;
	double	y;
	int	color;
}	t_double2D;

typedef struct s_int2D
{
	int	x;
	int	y;
}	t_int2D;

typedef struct s_settings
{
	t_double2D	offset;
	double		scale;
	int		xmax;
	int		ymax;
	t_int2D		border;
	double		thickness;
}	t_settings;

typedef struct s_segment
{
	t_double2D	coef;
	t_int2D	max;
	t_int2D	min;
	double	dist;
	double	angle;
}	t_segment;

//map
t_map	*get_the_map(int argc, char *argv[]);

//main
void	print_map(t_map *map);

//window
void	put_pixel(t_img *data, int x, int y, int color);

//projection
void	map_projection(t_map *map, t_img *img, t_settings settings);

//segment
void	draw_segment(t_img *img, t_double2D coord1, t_double2D coord2, t_settings settings);

//color
int	to_trgb(int t, int r, int g, int b);
int	to_t(int trgb);
int	to_r(int trgb);
int	to_g(int trgb);
int	to_b(int trgb);

#endif
