/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsort_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:22:11 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/27 21:51:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return the less cost for placing the i-th item of a before the j-th item of b
int	evaluate(int i, int j, t_stack *a, t_stack *b)
{
	int	disjoin_cost;
	int	join_cost;
	int	cost;
	int	a_cost;
	int	b_cost;

	cost = 1;
	a_cost = min(i, a->size - i);
	b_cost = min(j, b->size - j);
	if (i == 0)
		return (cost + b_cost);
	if (j == 0)
		return (cost + a_cost);
	//joined version (use of rr,rrr, ra and rb)
	join_cost = 1;
	join_cost += min(a_cost, b_cost) + dist_ij;
	//disjoined version (use of ra and rb)
	disjoin_cost = 1;
	disjoin_cost += a_cost + b_cost;
	return (min(join_cost, disjoin_cost));
}

//search for the best item in the a stack to place in the b stack and return his index
int	choose_item(t_stack *a, t_stack *b)
{
	int	best_item;
	int	best_cost;
	int	cost;
	int	i;

	if (a->size < 2 || b->size < 2)
		return (0);
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
//looks like the insert sort but place the less cost item instead of the top item of a
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
