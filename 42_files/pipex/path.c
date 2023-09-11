/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:44:53 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/10 12:47:58 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_free(char **path)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		sec_alloc(path[i], 1);
		i++;
	}
	sec_alloc(path, 1);
}

char	**init_path(char *envp[])
{
	char	**path;

	while (*envp != NULL && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == NULL)
		return (NULL);
	path = sec_alloc(ft_split(*envp + 5, ':'), 0);
	return (path);
}

char	**find_cmd_path(char **cmd, char **path)
{
	char	*test_path;
	char	*tmp;

	while (*path != NULL)
	{
		tmp = sec_alloc(ft_strjoin(*path, "/"), 0);
		if (tmp == NULL)
			return (NULL);
		test_path = sec_alloc(ft_strjoin(tmp, cmd[0]), 0);
		if (test_path == NULL)
			return (NULL);
		sec_alloc(tmp, 1);
		if (!access(test_path, F_OK | X_OK))
		{
			sec_alloc(cmd[0], 1);
			cmd[0] = test_path;
			return (cmd);
		}
		sec_alloc(test_path, 1);
		path++;
	}
	return (cmd);
}
