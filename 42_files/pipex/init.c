/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:11:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/10 12:43:36 by gdornic          ###   ########.fr       */
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

char	***exit_init(char ***cmd, char **path)
{
	cmd_free(cmd);
	if (path != NULL)
		path_free(path);
	return (NULL);
}

char	***init_cmd(int argc, char *argv[], char *envp[])
{
	char	***cmd;
	char	**path;
	int		i;
	int		len;
	int		start;

	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]) + 1))
		start = 2;
	else
		start = 3;
	len = argc - 3;
	cmd = (char ***)sec_alloc(malloc(sizeof(char **) * (len + 1)), 0);
	if (cmd == NULL)
		return (NULL);
	path = init_path(envp);
	if (path == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cmd[i] = split_arg(argv[start + i]);
		if (cmd[i] == NULL)
			return (NULL);
		cmd[i] = find_cmd_path(cmd[i], path);
		if (cmd[i] == NULL)
			return (NULL);
		i++;
	}
	cmd[i] = NULL;
	path_free(path);
	return (cmd);
}
