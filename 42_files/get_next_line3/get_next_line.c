/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:29:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/24 04:26:43 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_addnstack(char *line, char *stack, size_t n)
{
	char	*tmp;

	if (line == NULL)
	{
		line = (char *)malloc(sizeof(char));
		ft_memset(line, '\0', 1);
	}
	tmp = line;
	line = ft_strnjoin(tmp, stack, n);
	free(tmp);
	return (line);
}

static char	*get_the_line(int fd, char *stack)
{
	char	*line;
	char	*first_occ;
	ssize_t	read_size;

	if (stack[0] == '\0')
	{
		ft_memset(stack, '\0', BUFFER_SIZE + 1);
		read_size = read(fd, stack, BUFFER_SIZE);
		if (read_size <= 0)
			return (NULL);
	}
	first_occ = ft_strchr(stack, '\n');
	line = NULL;
	while (first_occ == NULL && stack[0] != '\0')
	{
		line = ft_addnstack(line, stack, BUFFER_SIZE);
		ft_memset(stack, '\0', BUFFER_SIZE);
		read_size = read(fd, stack, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		first_occ = ft_strchr(stack, '\n');
	}
	line = ft_addnstack(line, stack, (first_occ - stack + 1));
	ft_stackmove(stack, first_occ);
	return (line);
}

static char	*fast_get_line(int fd)
{
	static char	stack[BUFFER_SIZE + 1];
	char		*line;

	line = get_the_line(fd, stack);
	return (line);
}

static char	*slow_get_line(int fd)
{
	static char	*stack;
	char		*line;

	if (stack == NULL)
	{
		stack = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		ft_memset(stack, '\0', BUFFER_SIZE + 1);
		if (stack == NULL)
			return (NULL);
	}
	line = get_the_line(fd, stack);
	if (line == NULL)
		free(stack);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || fd > 4096)
		return (NULL);
	if (BUFFER_SIZE > 8191999)
		line = fast_get_line(fd);
	else
		line = slow_get_line(fd);
	return (line);
}
