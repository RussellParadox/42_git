/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:49 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/14 16:41:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shield.h"

void	free_array_nodes(void *node, size_t size, unsigned int dimension)
{
	if (node == NULL)
		return ;
	while (*(void **)node != NULL)
	{
		if (dimension > 2)
			free_array_nodes(*(void **)node, size, dimension - 1);
		free(*(void **)node);
		node += size;
	}
}

//free each dimension of a dynamic multi-dimensionnal array NULL terminated on any other dimension than the first
void	free_array(void *root, unsigned int dimension)
{
	if (root == NULL)
		return ;
	free_array_nodes(root, sizeof(void *), dimension);
	free(root);
}
