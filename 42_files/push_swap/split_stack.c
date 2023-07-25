/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 05:51:10 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 06:27:52 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_median(t_stack *a, t_stack *b)
{
	int	median;
	int	size;
	int	i;

	median = stack_median(a, 0, a->size - 1);
	size = a->size;
	i = 0;
	while (i < size)
	{
		if (a->item[0] < median)
			ps_npush(a, b, 1);
		else
			ps_nrotate(a, 1);
		i++;
	}
}
