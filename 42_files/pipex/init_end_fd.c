/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_end_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:40:22 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/18 18:52:22 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	place_cursor_eof(int fd)
{
	char	buff;

	while (read(fd, &buff, 1) > 0)
	{
	}
}

int	init_end_fd(int end_fd[2], int argc, char *argv[])
{
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc") + 1))
	{
		if (argv[2][0] == '\0')
		{
			shell_error("parse error near `|'", NULL);
			return (1);
		}
		if (here_doc(end_fd, argv))
			return (1);
		end_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT, \
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		place_cursor_eof(end_fd[1]);
	}
	else
	{
		end_fd[0] = open(argv[1], O_RDONLY);
		if (end_fd[0] == -1)
			shell_error(strerror(errno), argv[1]);
		end_fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, \
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	}
	if (end_fd[1] == -1)
		perror("open");
	return (0);
}
