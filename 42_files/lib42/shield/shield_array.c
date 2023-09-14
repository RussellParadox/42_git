/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:42:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/14 16:00:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shield.h"

void	*shield_node(void *node, size_t size, unsigned int dimension, int mode)
{
	void	*continue_prev_dim;

	if (node == NULL)
		return (NULL);
	continue_prev_dim = (void *)1;
	while (*(void **)node != NULL)
	{
		if (dimension > 2)
		{
			if (shield_node(*(void **)node, size, dimension - 1, mode) == NULL)
				continue_prev_dim = NULL;
		}
		if (shield(*(void **)node, mode) == NULL && mode == -1)
			continue_prev_dim = NULL;
		if (continue_prev_dim == NULL)
			free(*(void **)node);
		node += size;
	}
	return (continue_prev_dim);
}

//use shield() on each dimension of an array where each dimension of the array terminate with NULL except the first dimension(root)
//size need to be the size of a pointer to the data stored in the array tree
void	*shield_array(void *root, size_t size, unsigned int dimension, int mode)
{
	if (root == NULL)
		return (shield(NULL, 0));
	if (mode == 0)
		mode = -1;
	if (shield_node(root, size, dimension, mode) == NULL)
	{
		free(root);
		return (NULL);
	}
	return (shield(root, mode));
}
