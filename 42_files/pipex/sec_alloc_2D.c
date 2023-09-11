/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_alloc_2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:42:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/11 17:01:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//use sec_alloc() on 2 dimensionnal arrays, array must terminate with a NULL pointer
void	*sec_alloc_2D(void *array, size_t size, int mode)
{
	int	i;

	if (array == NULL)
		return (sec_alloc(NULL, 0));
	i = 0;
	while (*(void **)(array + i * size) != NULL)
	{
		sec_alloc(*(void **)(array + i * size), mode);
		i++;
	}
	return (sec_alloc(array, mode));
}
