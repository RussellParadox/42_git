/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:11:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/15 11:11:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_free(t_list **cmd)
{
	int	i;

	if (cmd != NULL)
	{
		i = 0;
		while (cmd[i] != NULL)
		{
			ft_lstclear(&cmd[i], free);
			i++;
		}
		free(cmd);
	}
}

int	split_len(char **split)
{
	int	len;

	len = 0;
	while (split[len] != NULL)
		len++;
	return (len);
}

t_list	**exit_init(t_list **cmd)
{
	cmd_free(cmd);
	return (NULL);
}

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
