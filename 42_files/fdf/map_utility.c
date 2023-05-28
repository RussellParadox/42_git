/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:35:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/05/28 16:36:48 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->max.x)
	{
		free(map->height[i]);
		free(map->color[i]);
		i++;
	}
	free(map->height);
	free(map->color);
	free(map);
}

int	get_map_color(char *cptr)
{
	char	*comma_occ;
	int		exponent;
	int		color;

	comma_occ = ft_strchr(cptr, ',');
	if (comma_occ == NULL)
		return (-1);
	comma_occ = ft_strchr(comma_occ, '\0') - 1;
	color = 0;
	exponent = 0;
	while (*comma_occ != 'x')
	{
		if (!ft_isdigit(*comma_occ))
		{
			if (*comma_occ >= 'a')
				color += (*comma_occ - 'a' + 10) * pow(16, exponent);
			else
				color += (*comma_occ - 'A' + 10) * pow(16, exponent);
		}
		else
			color += (*comma_occ - '0') * pow(16, exponent);
		comma_occ--;
		exponent++;
	}
	return (color);
}

int	chr_count_until(char *file, char *set, char lim)
{
	int	chr_qt;
	int	i;

	chr_qt = 0;
	i = 0;
	while (file[i] && file[i] != lim)
	{
		if (ft_strchr(set, file[i]))
		{
			chr_qt++;
			while (file[i] && ft_strchr(set, file[i]))
				i++;
		}
		else
			i++;
	}
	return (chr_qt);
}

int	check_map_format(char *file, int xmax, int ymax)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	x = 0;
	while (x < xmax)
	{
		y = chr_count_until(&file[i], ",x-0123456789abcdefABCDEF", '\n') - 1;
		if (y != ymax)
		{
			ft_printf("Wrong map: error at line %d\n", x);
			return (1);
		}
		while (file[i] && file[i] != '\n')
			i++;
		i++;
		x++;
	}
	return (0);
}
