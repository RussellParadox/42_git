/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:44:53 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/09 14:46:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
