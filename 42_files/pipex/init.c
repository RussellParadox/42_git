/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:11:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/17 15:30:53 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	cmd = shield(malloc(sizeof(char **) * (len + 1)), 2);
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
	//shield_array(path, 2, 1);
	return (cmd);
}
