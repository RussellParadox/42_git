/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:52:22 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 06:40:58 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//perform a traditional array swap on a with push swap instructions
//note that i < j
void	array_swap(t_stack *a, t_stack *b, int i, int j)
{
	if (i == j)
		return ;
	if (j < i)
		ptr_swap(&i, &j);
	if (i < a->size - i)
		ps_nrotate(a, i);
	else
		ps_nrrotate(a, a->size - i);
	if (i + 1 == j)
		ps_nswap(a, 1);
	else
	{
		ps_npush(a, b, 1);
		if (j - i - 1 < i + a->size - j + 1)
			ps_nrotate(a, j - i - 1);
		else
			ps_nrrotate(a, i + a->size - j + 1);
		ps_npush(b, a, 1);
		ps_nrotate(a, 1);
		ps_npush(a, b, 1);
		if (j - i < i + a->size - j)
			ps_nrrotate(a, j - i);
		else
			ps_nrotate(a, i + a->size - j);
		ps_npush(b, a, 1);
	}
	if (i < a->size - i)
		ps_nrrotate(a, i);
	else
		ps_nrotate(a, a->size - i);
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
static void	quick_sort_stack(t_stack *a, t_stack *b, int first, int last)
{
	int	pivot;

	if (first < last)
	{
		pivot = partition(a, b, first, last);
		quick_sort_stack(a, b, first, pivot);
		quick_sort_stack(a, b, pivot + 1, last);
	}
}

void	quick_sort(t_stack *a, t_stack *b)
{
	quick_sort_stack(a, b, 0, a->size - 1);
}
