/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 01:47:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/24 02:50:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_cmd(char **cmd, int io_fd[4], char *envp[], char *pathname)
{
	if (pathname == NULL)
		exit(0);
	if (io_fd[2] != -1 && close(io_fd[2]) == -1)
		perror("close");
	if (io_fd[3] != -1 && close(io_fd[3]) == -1)
		perror("close");
	if (io_fd[0] != -1 && dup2(io_fd[0], 0) == -1)
		perror("dup2");
	if (io_fd[1] != -1 && dup2(io_fd[1], 1) == -1)
		perror("dup2");
	if (execve(pathname, cmd, envp) == -1)
		perror("execve");
	exit(0);
}

//io_fd[0]: input fd
//io_fd[1]: output fd
//io_fd[2]: pipe input to close
//io_fd[3]: pipe output to close
int	pipex(char ***cmd, int end_fd[2], char *envp[], int cmd_qt)
{
	pid_t	pid;
	char	*pathname;
	int		io_fd[4];
	int		i;

	i = 0;
	while (i < cmd_qt)
	{
		choose_io_fd(io_fd, i, cmd_qt, end_fd);
		pathname = find_cmd_path(cmd[i], init_path(envp));
		pid = fork();
		if (pid < 0)
			perror("fork");
		else if (pid == 0)
			execute_cmd(cmd[i], io_fd, envp, pathname);
		else
		{
			waitpid(pid, NULL, WNOHANG);
			if ((++i && io_fd[0] != -1 && close(io_fd[0])) \
			|| (io_fd[2] != -1 && close(io_fd[2])))
				perror("close");
		}
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmd;
	int		end_fd[2];

	if (*envp == NULL)
		return (EXIT_FAILURE);
	if (argc < 5 || (!ft_strncmp(argv[1], "here_doc", \
	ft_strlen(argv[1]) + 1) && argc < 6))
		return (EXIT_FAILURE);
	init_shell_error(envp);
	if (init_end_fd(end_fd, argc, argv) && !shield(NULL, 2))
		return (EXIT_FAILURE);
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]) + 1))
		argc--;
	cmd = init_cmd(argc, argv);
	if (cmd == NULL && !shield(NULL, 2))
		return (EXIT_FAILURE);
	if (pipex(cmd, end_fd, envp, argc - 3) && !shield(NULL, 2))
		return (EXIT_FAILURE);
	if (close(end_fd[1]) == -1)
		perror("close");
	shield(NULL, 2);
	return (EXIT_SUCCESS);
}
