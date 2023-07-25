/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistic_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:51:17 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 06:29:43 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_stack *s)
{
	int	min;
	int	i;

	min = s->item[0];
	i = 1;
	while (i < s->size)
	{
		if (s->item[i] < min)
			min = s->item[i];
		i++;
	}
	return (min);
}

int	stack_max(t_stack *s)
{
	int	max;
	int	i;

	max = s->item[0];
	i = 1;
	while (i < s->size)
	{
		if (s->item[i] > max)
			max = s->item[i];
		i++;
	}
	return (max);
}

//return 1 if array is sorted, else return 0
int	is_rsorted(int *array, int size)
{
	int	n;
	int	i;

	if (size <= 1)
		return (1);
	n = size - 1;
	i = 0;
	while (i < n)
	{
		if (array[i] < array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

//return 1 if array is sorted, else return 0
int	is_sorted(int *array, int size)
{
	int	n;
	int	i;

	if (size <= 1)
		return (1);
	n = size - 1;
	i = 0;
	while (i < n)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	stack_median(t_stack *s, int first, int last)
{
	int	median;
	int	size;
	int	*cpy;
	int	i;

	size = last - first + 1;
	cpy = (int *)malloc(sizeof(int) * size);
	if (cpy == NULL)
		return (0);
	i = first;
	while (i <= last)
	{
		cpy[i] = s->item[i];
		i++;
	}
	quick_sort_array(cpy, first, last);
	median = cpy[size / 2];
	free(cpy);
	return (median);
}
