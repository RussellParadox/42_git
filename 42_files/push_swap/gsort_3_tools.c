/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsort_3_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:03:55 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/28 00:00:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_min(int x1, int x2)
{
	return ((x1 <= x2) * x1 + (x1 > x2) * x2);
}

int	int_dist(int x1, int x2)
{
	return ((x1 <= x2) * (x2 - x1) + (x2 < x1) * (x1 - x2));
}

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
	int	nearest_sup;
	int	position;
	int	i;

	nearest_sup = stack_max(s);
	position = 0;
	i = 0;
	while (i < s->size)
	{
		if (s->item[i] > n && s->item[i] <= nearest_sup)
		{
			nearest_sup = s->item[i];
			position = i;
		}
		i++;
	}
	return (position + 1);
}
