/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gsort_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 02:04:16 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 03:02:34 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gsort_1(t_stack *a, t_stack *b)
{
	int	rotation_count;

	while (!is_sorted(a->item, a->size))
	{
		rotation_count = 0;
		while (rotation_count < a->size - 1 && !is_sorted(a->item, a->size))
		{
			if (a->item[0] > a->item[1])
				ps_nswap(a, 1);
			ps_nrotate(a, 1);
			rotation_count++;
		}
		ps_npush(a, b, 1);
	}
	while (b->size > 0)
	{
		ps_npush(b, a, 1);
		ps_nrotate(a, 1);
	}
}
