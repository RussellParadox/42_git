/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsort_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:22:11 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 14:51:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_rotate(t_stack *a, t_stack *b, int i, int j)
{
	int	a_cost;
	int	b_cost;

	a_cost = int_min(i, a->size - i);
	b_cost = int_min(j, b->size - j);
	if (a_cost != i)
	{
		ps_nrrr(a, b, a_cost);
		j = (j + a_cost) % b->size;
	}
	else
	{
		ps_nrr(a, b, a_cost);
		j = (j - a_cost) % b->size;
		if (j < 0)
			j = b->size - j;
	}
	b_cost = int_min(j, b->size - j);
	if (b_cost != j)
		ps_nrrotate(b, b_cost);
	else
		ps_nrotate(b, b_cost);
}

//place item at i-th index in a at his place (descending order) in b
//cost[0] -> cost of a
//cost[1] -> cost of b
void	place_item(int i, t_stack *a, t_stack *b)
{
	int	cost[2];
	int	j;

	j = position(a->item[i], b);
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
			ps_nrrotate(a, cost[0]);
		else
			ps_nrotate(a, cost[0]);
		if (cost[1] != j)
			ps_nrrotate(b, cost[1]);
		else
			ps_nrotate(b, cost[1]);
	}
	ps_npush(a, b, 1);
}

//return the less cost for placing the i-th item of a before the j-th item of b
//joined version: use of rr,rrr, ra and rb
//disjoined version: use of ra and rb
int	evaluate(int i, int j, t_stack *a, t_stack *b)
{
	int	disjoin_cost;
	int	join_cost;
	int	a_cost;
	int	b_cost;

	if (b->size < 1)
		return (1);
	a_cost = int_min(i, a->size - i);
	b_cost = int_min(j, b->size - j);
	join_cost = evaluate_join_cost(i, j, a, b);
	disjoin_cost = 1 + a_cost + b_cost;
	return (int_min(join_cost, disjoin_cost));
}

//search for the best item in the a stack to place in the b stack and
//return his index
int	choose_item(t_stack *a, t_stack *b)
{
	int	best_item;
	int	best_cost;
	int	cost;
	int	i;

	best_cost = evaluate(0, position(a->item[0], b), a, b);
	best_item = 0;
	i = 1;
	while (i < a->size)
	{
		cost = evaluate(i, position(a->item[i], b), a, b);
		if (cost < best_cost)
		{
			best_item = i;
			best_cost = cost;
		}
		i++;
	}
	return (best_item);
}

//algorithm that use rotation and push instructions
//looks like the insert sort but place the less cost
//item instead of the top item of a
void	gsort_3(t_stack *a, t_stack *b)
{
	int	i;

	while (a->size > 0)
	{
		i = choose_item(a, b);
		place_item(i, a, b);
	}
	i = locate_max(b);
	if (i < b->size - i)
		ps_nrotate(b, i);
	else
		ps_nrrotate(b, b->size - i);
	ps_npush(b, a, b->size);
}
