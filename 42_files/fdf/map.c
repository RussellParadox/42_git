/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:59:04 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/14 23:22:31 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->max.y)
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
	int	exponent;
	int	color;

	comma_occ = ft_strchr(cptr, ',');
	if (comma_occ == NULL)
		return (-1);
	comma_occ = ft_strchr(comma_occ, '\0');
	comma_occ--;
	color = 0;
	exponent = 0;
	while (*comma_occ != 'x')
	{
		if (!ft_isdigit(*comma_occ))
			color += (*comma_occ - 'A' + 10) * pow(16, exponent);
		else
			color += (*comma_occ - '0') * pow(16, exponent);
		comma_occ--;
		exponent++;
	}
	return (color);
}

t_map	*load_heights(t_map *map, char ***splited_map)
{
	int	i;
	int	j;

	map->height = (int **)malloc((map->max.y + 1) * sizeof(int *));
	map->color = (int **)malloc((map->max.y + 1) * sizeof(int *));
	map->color_profile = 1;
	i = 0;
	while (i < map->max.y + 1)
	{
		map->height[i] = (int *)malloc((map->max.x + 1) * sizeof(int));
		map->color[i] = (int *)malloc((map->max.x + 1) * sizeof(int));
		j = 0;
		while (j < map->max.x + 1)
		{
			map->height[i][j] = ft_atoi(splited_map[i][j]);
			map->color[i][j] = get_map_color(splited_map[i][j]);
			if (map->color[i][j] != -1)
				map->color_profile = 0;
			if (map->height[i][j] > map->apex.z)
				map->apex = (t_int3D){.x=i, .y=j, .z=map->height[i][j]};
			else if (map->height[i][j] < map->abyss.z)
				map->abyss = (t_int3D){.x=i, .y=j, .z=map->height[i][j]};
			free(splited_map[i][j]);
			j++;
		}
		free(splited_map[i]);
		i++;
	}
	free(splited_map);
	return (map);
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

char	***split_the_file(char *file, int row_qt)
{
	char	**row_split;
	char	***col_split;
	int		i;

	row_split = ft_split(file, '\n');
	col_split = (char ***)malloc((unsigned int)row_qt * sizeof(char **));
	i = 0;
	while (i < row_qt)
	{
		col_split[i] = ft_split(row_split[i], ' ');
		free(row_split[i]);
		i++;
	}
	free(row_split);
	return (col_split);
}

char	*get_the_file(char *file_name)
{
	int		fd;
	char	*file;
	char	*line;
	char	*tmp;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	file = ft_strdup("");
	while (line != NULL && file != NULL)
	{
		tmp = file;
		file = ft_strjoin(file, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (file);
}

t_map	*get_the_map(int argc, char *argv[])
{
	t_map		*map;
	char		*file;
	char		***splited_file;

	map = (t_map *)malloc(sizeof(t_map));
	file = get_the_file(argv[argc - 1]);
	map->max.y = chr_count_until(file, "\n", '\0') - 1;
	map->max.x = chr_count_until(file, ",x-0123456789", '\n') - 1;
	map->apex = (t_int3D){.x=0,.y=0,.z=0};
	map->abyss = (t_int3D){.x=0,.y=0,.z=0};
	splited_file = split_the_file(file, map->max.y + 1);
	free(file);
	map = load_heights(map, splited_file);
	return (map);
}
