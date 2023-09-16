/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 01:47:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/16 22:47:56 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_end_fd(int end_fd[2], int argc, char *argv[])
{
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc") + 1))
		here_doc(end_fd, argv);
	else
	{
		end_fd[0] = open(argv[1], O_RDONLY);
		if (end_fd[0] == -1)
			perror("open");
	}
	end_fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (end_fd[1] == -1)
		perror("open");
}

void	choose_io_fd(int io_fd[4], int i, int cmd_qt, int end_fd[2])
{
	static int	pipe_fd[2];

	if (i == 0)
	{
		io_fd[0] = end_fd[0];
		if (pipe(pipe_fd) == -1)
			perror("pipe");
		io_fd[1] = pipe_fd[1];
		io_fd[2] = -1;
		io_fd[3] = pipe_fd[0];
	}
	else if (i == cmd_qt - 1)
	{
		io_fd[0] = pipe_fd[0];
		io_fd[1] = end_fd[1];
		io_fd[2] = pipe_fd[1];
		io_fd[3] = -1;
	}
	else
	{
		io_fd[0] = pipe_fd[0];
		io_fd[2] = pipe_fd[1];
		if (pipe(pipe_fd) == -1)
			perror("pipe");
		io_fd[1] = pipe_fd[1];
		io_fd[3] = pipe_fd[0];
	}
}

int	execute_cmd(char **cmd, int io_fd[4], char *envp[])
{
	if (io_fd[2] != -1 && close(io_fd[2]) == -1)
	{
		perror("close");
		exit(1);
	}
	if (io_fd[3] != -1 && close(io_fd[3]) == -1)
	{
		perror("close");
		exit(1);
	}
	if (io_fd[0] != -1 && dup2(io_fd[0], 0) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (io_fd[1] != -1 && dup2(io_fd[1], 1) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (execve(cmd[0], cmd, envp) == -1)
	{
		perror("execve");
		exit(1);
	}
	exit(0);
}

//io_fd[0]: input fd
//io_fd[1]: output fd
//io_fd[2]: pipe input to close
//io_fd[3]: pipe output to close
int	pipex(char ***cmd, int end_fd[2], char *envp[], int cmd_qt)
{
	pid_t	pid;
	int	io_fd[4];
	int	i;

	i = 0;
	while (i < cmd_qt)
	{
		choose_io_fd(io_fd, i, cmd_qt, end_fd);
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
			execute_cmd(cmd[i], io_fd, envp);
		else
		{
			waitpid(pid, NULL, WNOHANG);
			if (io_fd[0] != -1 && close(io_fd[0]))
				perror("close");
			if (io_fd[2] != -1 && close(io_fd[2]))
				perror("close");
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmd;
	int		end_fd[2];

	if (argc < 5 || (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]) + 1) && argc < 6))
		return (EXIT_FAILURE);
	init_end_fd(end_fd, argc, argv);
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]) + 1))
		argc--;
	cmd = init_cmd(argc, argv, envp);
	if (cmd == NULL && !shield(NULL, 2))
		return (EXIT_FAILURE);
	if (pipex(cmd, end_fd, envp, argc - 3) && !shield(NULL, 2))
		return (EXIT_FAILURE);
	if (close(end_fd[1]) == -1)
		perror("close");
	shield(NULL, 2);
	return (EXIT_SUCCESS);
}
