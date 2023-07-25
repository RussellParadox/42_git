/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:52:22 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 03:35:22 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//a partition version who limitate the swap usage
static int	partition(int *array, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	pivot = array[first];
	i = first - 1;
	j = last + 1;
	while (1)
	{
		j--;
		while (array[j] > pivot)
			j--;
		i++;
		while (array[i] < pivot)
			i++;
		if (i < j)
			ptr_swap(&array[i], &array[j]);
		else
			return (j);
	}
}

//the quick sort algorithm, implemented to sort the an array
void	quick_sort_array(int *array, int first, int last)
{
	int	pivot;

	if (first < last)
	{
		pivot = partition(array, first, last);
		quick_sort_array(array, first, pivot);
		quick_sort_array(array, pivot + 1, last);
	}
}
