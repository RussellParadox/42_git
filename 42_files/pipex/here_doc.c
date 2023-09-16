/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:33:51 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/16 22:53:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_here_doc(int pipe_fd[2], char *limit)
{
	int		limit_size;
	char	*line;

	limit_size = ft_strlen(limit) + 1;
	limit[limit_size - 1] = '\n';
	close(pipe_fd[0]);
	ft_printf("> ");
	line = get_next_line(0);
	while (line != NULL && ft_strncmp(line, limit, limit_size))
	{
		if (write(pipe_fd[1], line, ft_strlen(line)) == -1)
			perror("write");
		free(line);
		ft_printf("> ");
		line = get_next_line(0);
	}
	if (line != NULL)
		free(line);
	if (close(pipe_fd[1]) == -1)
		perror("close");
	exit(EXIT_SUCCESS);
}

void	here_doc(int end_fd[2], char *argv[])
{
	int	pipe_fd[2];
	int	pid;

	if (argv[2][0] == '\0')
		exit(EXIT_FAILURE);
	if (pipe(pipe_fd) == -1)
		perror("pipe");
	end_fd[0] = pipe_fd[0];
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
		exec_here_doc(pipe_fd, argv[2]);
	else
	{
		waitpid(pid, NULL, 0);
		if (close(pipe_fd[1]) == -1)
			perror("close");
	}
}
