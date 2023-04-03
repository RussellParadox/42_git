/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:00:43 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 21:00:04 by gdornic          ###   ########.fr       */
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
}	t_map;

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
}	t_double2D;

typedef struct s_int2D
{
	int	x;
	int	y;
}	t_int2D;

typedef struct s_set
{
	t_double2D	offset;
	double		scale;
	int		xmax;
	int		ymax;
	double		thickness;
}	t_set;

typedef struct s_segment
{
	double	intercept;
	double	slope_coef;
	double	xmax;
	double	xmin;
}	t_segment;

t_map	*get_the_map(int argc, char *argv[]);
void	print_map(t_map *map);
void	put_pixel(t_img *data, int x, int y, int color);
void	map_projection(t_map *map, t_img *img, t_set settings);

#endif
