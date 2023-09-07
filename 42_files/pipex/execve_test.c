/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:40:48 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/07 12:05:40 by gdornic          ###   ########.fr       */
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
	int	pipe_fd[2];
	char	buffer;

	i = 0;
	while (i < argc)
		printf("argv %d:%s\n", i++, argv[i]);
	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		while (read(0, &buffer, 1) > 0 && buffer != '\n')
			write(pipe_fd[1], &buffer, 1);
		close(pipe_fd[1]);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, WNOHANG);
		close(pipe_fd[1]);
	}
}
