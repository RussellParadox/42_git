/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:22:44 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/15 02:11:06 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_file(int fd)
{
	char	*file;
	char	*line;
	char	*tmp;

	file = ft_strdup("");
	if (file == NULL)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = file;
		file = ft_strjoin(file, line);
		if (file == NULL)
			break ;
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (file);
}

void	routine_fils(pid_t pid, char *argv[], char *envp[], int pipe_fd[2])
{
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], 1) == -1)
	{
		perror("dup2");
		close(pipe_fd[1]);
		exit(0);
	}
	if (execve(argv[0], argv, envp) == -1)
	{
		perror("execve");
		close(pipe_fd[1]);
		exit(1);
	}
	else
	{
		close(pipe_fd[1]);
		exit(0);
	}
}

void	routine_pere(pid_t pid, char *argv[], char *envp[], int pipe_fd[2])
{
	int	status;
	char	*pipe_out;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		if (!WEXITSTATUS(status))
		{
			close(pipe_fd[1]);
			pipe_out = get_file(pipe_fd[0]);
			close(pipe_fd[0]);
			if (pipe_out == NULL)
				perror("get_file");
			else
			{
				argv = set_argv(argv, pipe_out);
				if (execve(argv[0], argv, envp) == -1)
					perror("execve");
			}
		}
	}
	else
		perror("exit");
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int	pipe_fd[2];

	if (argc != 5)
		return (EXIT_FAILURE);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
		routine_fils(pid, argv + 1, envp, pipe_fd);
	else
		routine_pere(pid, argv + 3, envp, pipe_fd);
	return (EXIT_SUCCESS);
}
