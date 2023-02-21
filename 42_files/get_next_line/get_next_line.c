/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:54:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/21 19:20:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static _Bool	ft_belong_to(char c, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_free_tmp(char *tmp)
{
	free(tmp);
	return (NULL);
}

static char	*ft_fdtoline(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*line_tmp;
	ssize_t		read_size;

	line = ft_strjoin(buffer, "");
	if (line == NULL)
		return (NULL);
	read_size = 1;
	while (!ft_belong_to('\n', buffer) && read_size > 0)
	{
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
		read_size = read(fd, buffer, BUFFER_SIZE);
		line_tmp = line;
		line = ft_strjoin(line_tmp, buffer);
		if (line == NULL)
			return (ft_free_tmp(line_tmp));
		free(line_tmp);
	}
	line_tmp = line;
	line = ft_strdup_to('\n', line_tmp, buffer);
	if (line == NULL)
		return (ft_free_tmp(line_tmp));
	free(line_tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = ft_fdtoline(fd);
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
