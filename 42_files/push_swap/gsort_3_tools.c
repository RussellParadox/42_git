/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsort_3_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:03:55 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 14:45:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate_max(t_stack *s)
{
	int	i_max;
	int	max;
	int	i;

	i_max = 0;
	max = s->item[0];
	i = 1;
	while (i < s->size)
	{
		if (s->item[i] > max)
		{
			max = s->item[i];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

//return the position (descending order) of the n index in s
int	position(int n, t_stack *s)
{
	int	nearest_min;
	int	position;
	int	i;

	if (s->size == 0)
		return (0);
	nearest_min = stack_min(s);
	position = 0;
	i = 0;
	while (i < s->size)
	{
		if ((s->item[i] < n && s->item[i] > nearest_min) \
		|| (s->item[i] == nearest_min))
		{
			nearest_min = s->item[i];
			position = i;
		}
		i++;
	}
	if (nearest_min > n)
		position++;
	if (position == s->size)
		position = 0;
	return (position);
}

int	actualise_joined_index(int i1, int i2, int cost, int size)
{
	if (cost != i2)
		i1 = (i1 + cost) % size;
	else
		i1 = (i1 - cost) % size;
	if (i1 < 0)
		i1 = size - i1;
	return (i1);
}

int	evaluate_join_cost(int i, int j, t_stack *a, t_stack *b)
{
	int	join_cost;
	int	a_cost;
	int	b_cost;

	a_cost = int_min(i, a->size - i);
	b_cost = int_min(j, b->size - j);
	join_cost = 1 + int_min(a_cost, b_cost);
	if (a_cost <= b_cost)
	{
		j = actualise_joined_index(j, i, a_cost, b->size);
		join_cost += int_min(j, b->size - j);
	}
	else
	{
		i = actualise_joined_index(i, j, b_cost, a->size);
		join_cost += int_min(i, a->size - i);
	}
	return (join_cost);
}
