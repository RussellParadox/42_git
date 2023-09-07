/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:11:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/07 15:46:11 by gdornic          ###   ########.fr       */
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

void	path_free(char **path)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		i++;
	}
	free(path);
}

int	split_len(char **split)
{
	int	len;

	len = 0;
	while (split[len] != NULL)
		len++;
	return (len);
}

char	***exit_init(char ***cmd, char **path)
{
	cmd_free(cmd);
	if (path != NULL)
		path_free(path);
	return (NULL);
}

char	**init_path(char *envp[])
{
	char	**path;

	while (*envp != NULL && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == NULL)
		return (NULL);
	path = ft_split(*envp + 5, ':');
	return (path);
}

char	**find_cmd_path(char **cmd, char **path)
{
	char	*test_path;
	char	*tmp;

	if (cmd == NULL)
		return (NULL);
	while (*path != NULL)
	{
		tmp = ft_strjoin(*path, "/");
		if (tmp == NULL)
			return (NULL);
		test_path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (test_path == NULL)
			return (NULL);
		if (!access(test_path, F_OK | X_OK))
		{
			free(cmd[0]);
			cmd[0] = test_path;
			return (cmd);
		}
		free(test_path);
		path++;
	}
	return (cmd);
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
	cmd = (char ***)malloc(sizeof(char **) * (len + 1));
	if (cmd == NULL)
		return (NULL);
	path = init_path(envp);
	if (path == NULL)
		return (exit_init(cmd, path));
	i = 0;
	while (i < len)
	{
		//cmd[i] = ft_split(argv[2 + i], ' ');
		cmd[i] = split_arg(argv[start + i]);
		cmd[i] = find_cmd_path(cmd[i], path);
		if (cmd[i] == NULL)
			return (exit_init(cmd, path));
		i++;
	}
	cmd[i] = NULL;
	path_free(path);
	return (cmd);
}
