/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 01:47:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/16 01:47:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **cmd, char *envp[], int pipe_fd[2], int pipeline_fd[2])
{
	close(pipe_fd[0]);
	if (dup2(pipeline_fd[0], 0) == -1)
	{
		perror("dup2");
		close(pipe_fd[1]);
		exit(1);
	}
	if (dup2(pipe_fd[1], 1) == -1)
	{
		perror("dup2");
		close(pipe_fd[1]);
		exit(1);
	}
	if (execve(cmd[0], cmd, envp) == -1)
	{
		perror("execve");
		close(pipe_fd[1]);
		exit(1);
	}
	close(pipe_fd[1]);
	exit(0);
}

void	parent_process(char **cmd, char *envp[], int pipe_fd[2], int pipeline_fd[2])
{
	close(pipe_fd[1]);
	if (dup2(pipeline_fd[1], 1) == -1)
	{
		perror("dup2");
		close(pipe_fd[0]);
		exit(1);
	}
	if (dup2(pipe_fd[0], 0) == -1)
	{
		perror("dup2");
		close(pipe_fd[0]);
		exit(1);
	}
	if (execve(cmd[0], cmd, envp) == -1)
	{
		perror("execve");
		close(pipe_fd[0]);
		exit(1);
	}
	close(pipe_fd[0]);
	exit(0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmd;
	pid_t	pid;
	int		pipeline_fd[2];
	int		pipe_fd[2];
	int		status;

	if (argc < 5)
		return (EXIT_FAILURE);
	pipeline_fd[0] = open(argv[1], O_RDONLY);
	if (pipeline_fd[0] == -1)
	{
		perror("open");
		return (EXIT_FAILURE);
	}
	pipeline_fd[1] = open(argv[argc - 1], O_RDONLY);
	if (pipeline_fd[1] == -1)
	{
		perror("open");
		return (EXIT_FAILURE);
	}
	cmd = init_cmd(argc - 3, argv + 2);
	if (cmd == NULL)
		return (EXIT_FAILURE);
	print_cmd(cmd);
	if (pipe(pipe_fd) == - 1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
		child_process(cmd[0], envp, pipe_fd, pipeline_fd);
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			return (EXIT_FAILURE);
		if (!WEXITSTATUS(status))
			parent_process(cmd[1], envp, pipe_fd, pipeline_fd);
	}
	close(pipeline_fd[0]);
	close(pipeline_fd[1]);
	cmd_free(cmd);
	return (EXIT_SUCCESS);
}
