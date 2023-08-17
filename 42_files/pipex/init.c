/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:11:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/17 18:15:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_free(char ***cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i] != NULL)
	{
		j = 0;
		while (cmd[i][j] != NULL)
		{
			free(cmd[i][j]);
			j++;
		}
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

int	split_len(char **split)
{
	int	len;

	len = 0;
	while (split[len] != NULL)
		len++;
	return (len);
}

char	***exit_init(char ***cmd)
{
	cmd_free(cmd);
	return (NULL);
}

int	init_argv(char *argv[], int argc)
{
	char	*tmp;

	tmp = argv[2];
	argv[2] = ft_strjoin(argv[2], " < ");
	if (argv[2] == NULL)
		return (0);
	tmp = argv[2];
	argv[2] = ft_strjoin(argv[2], argv[1]);
	free(tmp);
	if (argv[2] == NULL)
		return (0);
	tmp = argv[3];
	argv[3] = ft_strjoin(argv[3], " > ");
	if (argv[3] == NULL)
		return (0);
	tmp = argv[3];
	argv[3] = ft_strjoin(argv[3], argv[argc - 1]);
	free(tmp);
	if (argv[3] == NULL)
		return (0);
	return (1);
}

char	***init_cmd(int argc, char *argv[])
{
	char	***cmd;
	int		i;
	int		len;

	len = argc - 3;
	cmd = (char ***)malloc(sizeof(char **) * (len + 1));
	if (cmd == NULL)
		return (NULL);
	/*
	if (!init_argv(argv, argc))
		return (exit_init(cmd));
		*/
	i = 0;
	while (i < len)
	{
		cmd[i] = ft_split(argv[2 + i], ' ');
		if (cmd[i] == NULL)
			return (exit_init(cmd));
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
