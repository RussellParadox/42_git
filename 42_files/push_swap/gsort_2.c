/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsort_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 03:38:45 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 05:54:23 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bad_rneighbors(t_stack *s)
{
	if (s->item[1] == s->max && s->item[0] == s->min)
		return (1);
	return (0);
}

int	bad_neighbors(t_stack *s)
{
	if (s->item[0] == s->max && s->item[1] == s->min)
		return (1);
	return (0);
}

int	both_unsorted(t_stack *a, t_stack *b)
{
	return (!(is_sorted(a->item, a->size) || is_rsorted(b->item, b->size)));
}

int	are_sorted(t_stack *a, t_stack *b)
{
	return (is_sorted(a->item, a->size) && is_rsorted(b->item, b->size));
}

void	gsort_2(t_stack *a, t_stack *b)
{
	int	swap_a;
	int	swap_b;
	int	size;
	int	i;

	size = a->size;
	split_median(a, b);
	a->min = stack_min(a);
	a->max = stack_max(a);
	b->min = stack_min(b);
	b->max = stack_max(b);
	while (!are_sorted(a, b))
	{
		swap_a = (a->item[0] > a->item[1] && !bad_neighbors(a));
		swap_b = (b->item[0] < b->item[1] && !bad_rneighbors(b));
		if (swap_a && swap_b)
			ps_nss(a, b, 1);
		else if (swap_a)
			ps_nswap(a, 1);
		else if (swap_b)
			ps_nswap(b, 1);
		else if (both_unsorted(a, b))
			ps_nrr(a, b, 1);
		else if (is_sorted(a->item, a->size))
			ps_nrotate(b, 1);
		else
			ps_nrotate(a, 1);
		i++;
	}
	i = 0;
	while (i < size / 2)
	{
		ps_npush(b, a, 1);
		i++;
	}
}
