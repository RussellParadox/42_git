/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:40:48 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/09 11:42:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "pipex.h"

void	arr_test(int array[2])
{
	array[0] = 2;
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	char	*line;
	char	buffer;
	int	pid;
	int	pipe_fd[2];
	int	pipe_fd2[2];

	i = 0;
	while (i < argc)
		printf("argv %d:%s\n", i++, argv[i]);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		line = get_next_line(0);
		ft_putstr_fd(line, pipe_fd[1]);
		close(pipe_fd[1]);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		close(pipe_fd[1]);
	}
	pipe(pipe_fd2);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd2[0]);
		while (read(pipe_fd[0], &buffer, 1))
			ft_putchar_fd(buffer, pipe_fd2[1]);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		close(pipe_fd[0]);
		close(pipe_fd2[1]);
		while (read(pipe_fd2[0], &buffer, 1))
			ft_putchar_fd(buffer, 1);
		close(pipe_fd2[0]);
	}
}
