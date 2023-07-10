/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:52:22 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/07 05:47:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//init solution
int	*init_solution(t_stack *a)
{
	int	*solution;
	int	i;

	solution = (int *)malloc(size * sizeof(int));
	if (solution != NULL)
	{
		i = 0;
		while (i < a->size)
		{
			solution[i] = a->item[i];
			i++;
		}
	}
	return (solution);
}

//a partition version who limitate the swap usage
static int	partition(int *solution, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	pivot = solution[first];
	i = first - 1;
	j = last + 1;
	while (1)
	{
		j--;
		while (solution[j] > pivot)
			j--;
		i++;
		while (solution[i] < pivot)
			i++;
		if (i < j)
			ptr_swap(&solution[i], &solution[j]);
		else
			return (j);
	}
}
		

//the quick sort algorithm, implemented to sort an array of integer
void	quick_sort_solution(int *solution, int first, int last)
{
	int	pivot;

	if (first < last)
	{
		pivot = partition(solution, first, last);
		quick_sort_solution(solution, first, pivot);
		quick_sort_solution(solution, pivot + 1, last);
	}
}
