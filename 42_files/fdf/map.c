/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:59:04 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/17 15:16:28 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_map_data(t_map *map, int i, int j)
{
	if (map->color[i][j] != -1)
		map->color_profile = 0;
	if (map->height[i][j] > map->apex.z)
		map->apex = (t_int3D){.x = i, .y = j, .z = map->height[i][j]};
	else if (map->height[i][j] < map->abyss.z)
		map->abyss = (t_int3D){.x = i, .y = j, .z = map->height[i][j]};
}

t_map	*load_heights(t_map *map, char ***splited_map)
{
	int	i;
	int	j;

	map->height = (double **)malloc((map->max.x + 1) * sizeof(double *));
	map->color = (int **)malloc((map->max.x + 1) * sizeof(int *));
	map->color_profile = 1;
	i = 0;
	while (i < map->max.x + 1)
	{
		map->height[i] = (double *)malloc((map->max.y + 1) * sizeof(double));
		map->color[i] = (int *)malloc((map->max.y + 1) * sizeof(int));
		j = 0;
		while (j < map->max.y + 1)
		{
			map->height[i][j] = ft_atoi(splited_map[i][j]);
			map->color[i][j] = get_map_color(splited_map[i][j]);
			load_map_data(map, i, j);
			free(splited_map[i][j]);
			j++;
		}
		free(splited_map[i]);
		i++;
	}
	free(splited_map);
	return (map);
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
	free(row_split[i]);
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
	if (fd < 0)
	{
		ft_printf("File doesn't exist\n");
		return (NULL);
	}
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

	file = get_the_file(argv[argc - 1]);
	if (file == NULL)
		return (NULL);
	map = (t_map *)malloc(sizeof(t_map));
	map->apex = (t_int3D){.x = 0, .y = 0, .z = 0};
	map->abyss = (t_int3D){.x = 0, .y = 0, .z = 0};
	map->max.x = chr_count_until(file, "\n", '\0') - 1;
	map->max.y = chr_count_until(file, ",x-0123456789abcdefABCDEF", '\n') - 1;
	if (check_map_format(file, map->max.x, map->max.y))
	{
		free(map);
		return (NULL);
	}
	splited_file = split_the_file(file, map->max.x + 1);
	free(file);
	if (splited_file == NULL)
		return (NULL);
	map = load_heights(map, splited_file);
	return (map);
}
