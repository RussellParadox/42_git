/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:59:04 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 01:20:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**load_heights(t_map *map, char ***splited_map)
{
	int	**height;
	size_t	i;
	size_t	j;

	height = (int **)malloc((map->ymax + 1) * sizeof(int *));
	i = 0;
	while (i < map->ymax + 1)
	{
		height[i] = (int *)malloc((map->xmax + 1) * sizeof(int));
		j = 0;
		while (j < map->xmax + 1)
		{
			height[i][j] = ft_atoi(splited_map[i][j]);
			free(splited_map[i][j]);
			j++;
		}
		free(splited_map[i]);
		i++;
	}
	free(splited_map);
	return (height);
}

size_t	chr_count_until(char *file, char c, char lim)
{
	size_t	chr_qt;
	size_t	i;

	chr_qt = 0;
	i = 0;
	while (file[i] && file[i] != lim)
	{
		if (file[i] == c)
			chr_qt++;
		i++;
	}
	return (chr_qt);
}

char	***split_the_file(char *file, size_t row_qt)
{
	char	**row_split;
	char	***col_split;
	size_t		i;

	row_split = ft_split(file, '\n');
	col_split = (char ***)malloc(row_qt * sizeof(char **));
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
	char	*file;
	char	***splited_file;

	map = (t_map *)malloc(sizeof(t_map));
	file = get_the_file(argv[argc - 1]);
	map->ymax = chr_count_until(file, '\n', '\0') - 1;
	map->xmax = chr_count_until(file, ' ', '\n');
	splited_file = split_the_file(file, map->ymax);
	free(file);
	map->height = load_heights(map, splited_file);
	return (map);
}
