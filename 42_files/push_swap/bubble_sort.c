/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 06:58:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 07:20:07 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *s)
{
	s->min = stack_min(s);
	s->max = stack_max(s);
	while (!is_sorted(s->item, s->size))
	{
		if (s->item[0] > s->item[1] && !bad_neighbors(s))
			ps_nswap(s, 1);
		else if (!is_sorted(s->item, s->size))
			ps_nrotate(s, 1);
	}
}

void	rbubble_sort(t_stack *s)
{
	s->min = stack_min(s);
	s->max = stack_max(s);
	while (!is_rsorted(s->item, s->size))
	{
		if (s->item[0] < s->item[1] && !bad_rneighbors(s))
			ps_nswap(s, 1);
		else if (!is_rsorted(s->item, s->size))
			ps_nrotate(s, 1);
	}
}
