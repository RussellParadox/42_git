/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 01:47:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/15 11:41:22 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_content(char *str)
{
	ft_printf("\t%s\n", str);
}

void	print_cmd(t_list **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		ft_printf("command %d:\n", i);
		ft_lstiter(cmd[i], print_content);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_list	**cmd;
	pid_t	pid;
	char	*input;
	int		pipe_fd[2];
	int		i;

	if (argc < 5)
		return (EXIT_FAILURE);
	cmd = init_cmd(argc - 3, argv + 2);
	if (cmd == NULL)
		return (EXIT_FAILURE);
	print_cmd(cmd);
	/*
	input = argv[1];
	i = 0;
	while (i < argc - 3)
	{
		set_cmd_input(cmd, i, input);
		pid = fork();
		if (pid < 0)
			return (EXIT_FAILURE);
		else if (pid == 0)
			execute_cmd(cmd[i]);
		else
			get_next_input(pid, input);
		i++;
	}
	*/
	cmd_free(cmd);
	return (EXIT_SUCCESS);
}
