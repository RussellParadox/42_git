/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:44:53 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/18 16:08:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**init_path(char *envp[])
{
	char	**path;

	while (*envp != NULL && ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == NULL)
		return (NULL);
	path = shield_array(ft_split(*envp + 5, ':'), 2, 0);
	return (path);
}

char	*find_cmd_path(char **cmd, char **path)
{
	char	*test_path;
	char	*tmp;

	while (*path != NULL)
	{
		tmp = shield(ft_strjoin(*path, "/"), 0);
		if (tmp == NULL)
			return (NULL);
		test_path = shield(ft_strjoin(tmp, cmd[0]), 0);
		if (test_path == NULL)
			return (NULL);
		shield(tmp, 1);
		if (!access(test_path, F_OK | X_OK))
			return (test_path);
		shield(test_path, 1);
		path++;
	}
	return (NULL);
}
