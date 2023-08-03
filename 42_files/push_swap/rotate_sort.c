/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:17:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 14:33:00 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_rotate_sorted(t_stack *a)
{
	int	i_min;
	int	min;
	int	i;
	int	j;

	min = stack_min(a);
	i_min = 0;
	while (a->item[i_min] != min)
		i_min++;
	i = i_min;
	j = i_min + 1;
	while (1)
	{
		if (i == a->size)
			i = 0;
		if (j == a->size)
			j = 0;
		if (j == i_min)
			break ;
		if (a->item[i] > a->item[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	rotate_sort(t_stack *a)
{
	int	i_min;
	int	min;

	min = stack_min(a);
	i_min = 0;
	while (a->item[i_min] != min)
		i_min++;
	if (i_min < a->size - i_min)
		ps_nrotate(a, i_min);
	else
		ps_nrrotate(a, a->size - i_min);
}
