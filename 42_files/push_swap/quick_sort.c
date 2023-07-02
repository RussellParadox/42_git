/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:52:22 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/02 02:26:30 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return the index of the median value in array between first and last
int	median_pivot(int *array, int first, int last)
{
	return (array[first + (last - first) / 2]);
}

//partition the stack, the elements smaller than stack[pivot] are placed before him, and taller after, so the element at pivot is right placed
void	partition(t_stack *a, t_stack *b, int first, int last, int pivot)
{
}

//the quick sort algorithm, implemented with the push_swap instructions
//this algorithm is in-place, so b in only here for using the push_swap instructions and when we talk about stack it's about the initial elements in a
void	quick_sort(t_stack *a, t_stack *b, int first, int last)
{
	int	pivot;

	if (first < last)
	{
		pivot = median_pivot(a->item, first, last);
		pivot = partition(a, b, first, last, pivot);
		quick_sort(a, b, first, pivot - 1);
		quick_sort(a, b, pivot + 1, last);
	}
}
