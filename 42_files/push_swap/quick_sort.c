/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:52:22 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/04 05:31:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap two elements at index i1 and i2 in a->item
//first we ensure that i1 contain the lowest value
//before each rotation, we search for the lowest distance to know the direction
void	array_swap(t_stack *a, t_stack *b, int i1, int i2)
{
	if (i1 != i2)
	{
		if (i1 > i2)
			ptr_swap(&i1, &i2);
		ps_nrotate(a, i1);
		ps_npush(a, b, 1);
		ps_nrotate(a, i2 - i1 - 1);
		ps_npush(b, a, 1);
		ps_nrotate(a, 1);
		ps_npush(a, b, 1);
		ps_nrrotate(a, i2 - i1);
		ps_npush(b, a, 1);
		ps_nrrotate(a, i1);
	}
}

//return the index of the median value in array between first and last
int	median_pivot(int *array, int first, int last)
{
	return (first + (last - first) / 2);
}

//partition the stack, the elements lower than stack[pivot] are placed before him, and taller after, so the element at pivot is right placed
int	partition(t_stack *a, t_stack *b, int first, int last, int pivot)
{
	int	i;
	int	j;

	array_swap(a, b, pivot, last);
	j = first;
	i = first;
	while (i < last)
	{
		if (a->item[i] < a->item[last])
		{
			array_swap(a, b, i, j);
			j++;
		}
		i++;
	}
	array_swap(a, b, last, j);
	return (j);
}

//a partition version who limitate the swap usage
int	partition2(t_stack *a, t_stack *b, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	pivot = a->item[first];
	i = first - 1;
	j = last + 1;
	while (1)
	{
		j--;
		while (a->item[j] > pivot)
			j--;
		i++;
		while (a->item[i] < pivot)
			i++;
		if (i < j)
			array_swap(a, b, i, j);
		else
			return (j);
	}
}
		

//the quick sort algorithm, implemented with the push_swap instructions
//this algorithm is in-place, so b in only here for using the push_swap instructions and when we talk about stack it's about the initial elements in a
void	quick_sort(t_stack *a, t_stack *b, int first, int last)
{
	int	pivot;

	if (first < last)
	{
		pivot = partition2(a, b, first, last);
		quick_sort(a, b, first, pivot);
		quick_sort(a, b, pivot + 1, last);
	}
}
