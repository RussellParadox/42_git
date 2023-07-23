/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:07:22 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/23 05:25:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exchange_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	i;
	int	j;

	size = a->size;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a->item[i] > a->item[j])
				array_swap(a, b, i, j);
			j++;
		}
		i++;
	}
}
