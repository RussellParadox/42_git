/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:02:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/13 15:58:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//delete the node and his content, and reconnect the list
void	delete_node(t_list *list, t_list *node)
{
	t_list	*i;

	i = list;
	while (i->next != NULL && i->next != node)
		i = i->next;
	i->next = node->next;
	ft_lstdelone(node, free);
}

//return the pointer to the node of content
t_list	*node_of(void *content, t_list *list)
{
	t_list	*i;

	i = list;
	while (i != NULL && i->content != content)
		i = i->next;
	return (i);
}

// The main purpose is to manage and store securely all the allocations of the program.
// If content is NULL or an allocation fail every precedent
// allocation is free and NULL is returned.
// If mode is 0 the content is stored in the list and returned,
// if mode is more than 0 the content is removed from the list and NULL is returned,
// if mode is less than 0 the content is added, but in case of error it's not free.
void	*shield(void *content, int mode)
{
	static t_list	*alloc;
	t_list	*node;

	if (content == NULL)
	{
		ft_lstclear(&alloc, free);
		return (NULL);
	}
	if (mode > 0)
	{
		ft_printf("content: %p\n", content);
		delete_node(alloc, node_of(content, alloc));
		return (NULL);
	}
	node = ft_lstnew(content);
	if (node == NULL)
	{
		if (mode < 0)
		{
			free(content);
			content = NULL;
		}
		ft_lstclear(&alloc, free);
		return (NULL);
	}
	ft_lstadd_back(&alloc, node);
	return (content);
}
