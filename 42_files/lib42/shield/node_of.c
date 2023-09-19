/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:22:16 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/19 15:38:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shield.h"

//return the pointer to the node of content
t_list	*node_of(void *content, t_list *list)
{
	t_list	*i;

	i = list;
	while (i != NULL && i->content != content)
		i = i->next;
	return (i);
}
