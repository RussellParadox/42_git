/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_alloc_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:42:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/12 19:26:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//use sec_alloc() on 2 dimensionnal arrays, array must terminate with a NULL pointer
void	*sec_alloc_level(void *array, size_t size, int mode)
{
	void	**next_block;

	if (array == NULL)
		return (sec_alloc(NULL, 0));
	next_block = array;
	while (*next_block != NULL)
	{
		sec_alloc(*next_block, mode);
		next_block = (void *)next_block + size;
	}
	return (sec_alloc(array, mode));
}

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

void	free_array(void *root, size_t size, unsigned int dimension)
{
	if (root == NULL)
		return ;
	free_array_nodes(root, size, dimension);
	free(root);
}

/*
//use sec_alloc() on each dimension of an array where each dimension of the array terminate with NULL except the first dimension(root)
//size need to be the size of a pointer to the data stored in the array tree
void	*sec_alloc_array(void *root, size_t size, unsigned int dimension, int mode)
{
	if (root == NULL)
		return (sec_alloc(NULL, 0));
	if (dimension == 1)
	return (sec_alloc(root, mode));
}
*/
