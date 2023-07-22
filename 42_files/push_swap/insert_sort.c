/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:09:26 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 04:03:27 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the insert sort algorithm, implemented with the push_swap instuctions
void	insert_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	item_quantity;

	ps_push(a, b);
	ft_printf("pb\n");
	i = 0;
	item_quantity = a->size;
	while (i < item_quantity)
	{
		j = 0;
		while (j < b->size)
		{
			if (a->item[0] > b->item[j])
			{
				insert(a, b, j);
				break ;
			}
			j++;
		}
		if (j == b->size)
			insert(a, b, j);
		i++;
	}
	ps_npush(b, a, item_quantity + 1);
}
