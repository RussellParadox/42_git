/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:52:22 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 04:03:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//perform a traditional array swap on a with push swap instructions
//note that i < j
void	array_swap(t_stack *a, t_stack *b, int i, int j)
{
	ps_nrotate(a, i);
	ps_npush(a, b, 1);
	ps_nrotate(a, j - i - 1);
	ps_npush(b, a, 1);
	ps_nrotate(a, 1);
	ps_npush(a, b, 1);
	ps_nrrotate(a, j - i);
	ps_npush(b, a, 1);
	ps_nrrotate(a, i);
}

//a partition version who limitate the swap usage
static int	partition(t_stack *a, t_stack *b, int first, int last)
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

//the quick sort algorithm, implemented to sort the a stack
void	quick_sort(t_stack *a, t_stack *b, int first, int last)
{
	int	pivot;

	if (first < last)
	{
		pivot = partition(a, b, first, last);
		quick_sort(a, b, first, pivot);
		quick_sort(a, b, pivot + 1, last);
	}
}
