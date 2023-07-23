/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:06:46 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/23 07:11:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < a->size - 1)
	{
		min = i;
		j = i + 1;
		while (j < a->size)
		{
			if (a->item[j] < a->item[min])
				min = j;
			j++;
		}
		if (min != i)
			array_swap(a, b, i, min);
		i++;
	}
}
