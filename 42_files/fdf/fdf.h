/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:00:43 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/21 22:45:07 by gdornic          ###   ########.fr       */
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
# define WIN_X 1920
# define WIN_Y 1080

typedef struct s_int2D
{
	int	x;
	int	y;
	int	color;
}	t_int2D;

typedef struct s_circle
{
	t_int2D	center;
	int	radius;
}	t_circle;

typedef struct s_mlx
{
	void	*instance;
	void	*win;
	t_circle	*circle;
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

typedef struct s_int3D
{
	int	x;
	int	y;
	int	z;
}	t_int3D;

typedef struct s_map
{
	int	**height;
	int	**color;
	int	color_profile;
	t_int2D	max;
	t_int3D	apex;
	t_int3D	abyss;
}	t_map;

typedef struct s_settings
{
	t_int2D	offset;
	double		scale;
	t_int2D		max;
	t_int2D		border;
	double		thickness;
	int		color_profile;
	t_double2D	cursor_to_map;
	double		dist;
	t_double2D	obj_center;
}	t_settings;

typedef struct s_segment
{
	t_double2D	coef;
	t_int2D	max;
	t_int2D	min;
	double	dist;
	int	color_profile;
}	t_segment;

typedef struct s_param
{
	t_mlx	*mlx;
	t_map	*map;
	t_settings	*settings;
	int	translation;
}	t_param;

//map
t_map	*get_the_map(int argc, char *argv[]);
void	free_map(t_map *map);

//init
void	make_offset(t_map *map, t_settings *settings);
t_mlx	*init_mlx(t_settings *settings);
t_settings	*settings_init(t_double2D max, double thickness, t_map *map);

//window
void	put_pixel(t_img *data, int x, int y, int color);
int	print_map(t_map *map);
int	destroy_hook(t_mlx *mlx);

//projection
t_double2D	isometric_projection(t_int3D coord, t_map *map);
void	map_projection(t_map *map, t_img *img, t_settings settings);

//segment
void	draw_segment(t_img *img, t_double2D coord1, t_double2D coord2, t_settings settings);
t_int2D	scaling(t_double2D double_coord, t_settings settings);
void	bresenham_segment(t_img *img, t_int2D coord1, t_int2D coord2, t_settings settings);

//color
int	to_trgb(int t, int r, int g, int b);
int	to_t(int trgb);
int	to_r(int trgb);
int	to_g(int trgb);
int	to_b(int trgb);

#endif
