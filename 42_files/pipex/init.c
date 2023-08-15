/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:11:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/16 01:40:26 by gdornic          ###   ########.fr       */
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

char	***init_cmd(int len, char *argv[])
{
	char	***cmd;
	int		i;

	cmd = (char ***)malloc(sizeof(char **) * (len + 1));
	if (cmd == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cmd[i] = ft_split(argv[i], ' ');
		if (cmd[i] == NULL)
			return (exit_init(cmd));
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

/*
t_list	**init_cmd(int len, char *argv[])
{
	t_list	**cmd;
	t_list	*new;
	char	**content;
	int	content_len;
	int	i;

	cmd = (t_list **)malloc(sizeof(t_list *) * (len + 1));
	if (cmd == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cmd[i] = (t_list *)malloc(sizeof(t_list));
		if (cmd[i] == NULL)
			return (exit_init(cmd));
		i++;
	}
	i = 0;
	while (i < len)
	{
		content = ft_split(argv[i], ' ');
		if (content == NULL)
			return (exit_init(cmd));
		content_len = split_len(content) - 1;
		cmd[i]->content = content[content_len--];
		cmd[i]->next = NULL;
		while (content_len >= 0)
		{
			new = ft_lstnew(content[content_len]);
			if (new == NULL)
				return (exit_init(cmd));
			ft_lstadd_front(&cmd[i], new);
			content_len--;
		}
		free(content);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
*/
