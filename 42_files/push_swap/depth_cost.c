/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:07:02 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 16:29:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_rotate_silent(t_stack *a, t_stack *b, int i, int j)
{
	int	a_cost;
	int	b_cost;

	a_cost = int_min(i, a->size - i);
	b_cost = int_min(j, b->size - j);
	if (a_cost != i)
	{
		ps_snrrr(a, b, a_cost);
		j = (j + a_cost) % b->size;
	}
	else
	{
		ps_snrr(a, b, a_cost);
		j = (j - a_cost) % b->size;
		if (j < 0)
			j = b->size - j;
	}
	b_cost = int_min(j, b->size - j);
	if (b_cost != j)
		ps_snrrotate(b, b_cost);
	else
		ps_snrotate(b, b_cost);
}

//place item at i-th index in a at his place (descending order) in b
//cost[0] -> cost of a
//cost[1] -> cost of b
void	place_item_silent(int i, int j, t_stack *a, t_stack *b)
{
	int	cost[2];

	cost[0] = int_min(i, a->size - i);
	cost[1] = int_min(j, b->size - j);
	if (b->size > 0 && evaluate_join_cost(i, j, a, b) - 1 <= cost[0] + cost[1])
	{
		if (cost[0] <= cost[1])
			join_rotate(a, b, i, j);
		else
			join_rotate(b, a, j, i);
	}
	else
	{
		if (cost[0] != i)
			ps_snrrotate(a, cost[0]);
		else
			ps_snrotate(a, cost[0]);
		if (cost[1] != j)
			ps_snrrotate(b, cost[1]);
		else
			ps_snrotate(b, cost[1]);
	}
	ps_snpush(a, b, 1);
}

int	depth_evaluate(int i, t_stack *a, t_stack *b, int depth)
{

	cost = depth_evaluate(i, a, b, depth + 1);
	return (evaluate);
}
