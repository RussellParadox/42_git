/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsort_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:22:11 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/28 07:09:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//place item at i-th index in a at his place (descending order) in b
void	place_item(int i, t_stack *a, t_stack *b)
{
	int	a_cost;
	int	b_cost;
	int	join_cost;
	int	j;

	if (b->size < 1)
	{
		ps_npush(a, b, 1);
		return ;
	}
	j = position(a->item[i], b);
	a_cost = int_min(i, a->size - i);
	b_cost = int_min(j, b->size - j);
	join_cost = evaluate_join_cost(i, j, a, b) - 1;
	if (join_cost <= a_cost + b_cost)
	{
		if (a_cost <= b_cost)
		{
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
		else
		{
			if (b_cost != j)
			{
				ps_nrrr(a, b, b_cost);
				i = (i + b_cost) % a->size;
			}
			else
			{
				ps_nrr(a, b, b_cost);
				i = (i - b_cost) % a->size;
				if (i < 0)
					i = a->size - i;
			}
			a_cost = int_min(i, a->size - i);
			if (a_cost != i)
				ps_nrrotate(a, a_cost);
			else
				ps_nrotate(a, a_cost);
		}
		ps_npush(a, b, 1);
	}
	else
	{
		if (a_cost != i)
			ps_nrrotate(a, a_cost);
		else
			ps_nrotate(a, a_cost);
		if (b_cost != j)
			ps_nrrotate(b, b_cost);
		else
			ps_nrotate(b, b_cost);
		ps_npush(a, b, 1);
	}
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

//search for the best item in the a stack to place in the b stack and return his index
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
	//ft_printf("cost: %d\n", best_cost);
	return (best_item);
}

//algorithm that use rotation and push instructions
//looks like the insert sort but place the less cost item instead of the top item of a
void	gsort_3(t_stack *a, t_stack *b)
{
	int	i;

	while (a->size > 0)
	{
		//ps_print(a, b);
		i = choose_item(a, b);
		//ft_printf("item: %d\n", i);
		//ft_printf("b position: %d\n", position(a->item[i], b));
		place_item(i, a, b);
	}
	i = locate_max(b);
	if (i < b->size - i)
		ps_nrotate(b, i);
	else
		ps_nrrotate(b, b->size - i);
	ps_npush(b, a, b->size);
}
