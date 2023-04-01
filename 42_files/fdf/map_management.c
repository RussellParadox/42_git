/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:59:04 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 00:23:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***split_the_file(char *file)
{
	char	**row_split;
	char	***col_split;

	row_split = ft_split(line, '\n');

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

int	**get_the_map(int argc, char *argv[])
{
	t_map		*map;
	char	*file;
	char	***splited_file;

	map = malloc(sizeof(t_map));
	file = get_the_file(argv[argc - 1]);
	splited_file = split_the_file(file);
