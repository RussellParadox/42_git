/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:09:26 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/27 21:08:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//do n push
void	ps_npush(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_push(s1, s2);
		ft_printf("p%c\n", s2->id);
		i++;
	}
}

//do n rotations
void	ps_nrotate(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_rotate(s);
		ft_printf("r%c\n", s->id);
		i++;
	}
}

//do n reverse rotations
void	ps_nrrotate(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_rrotate(s);
		ft_printf("rr%c\n", s->id);
		i++;
	}
}

//insert a->item[0] at place of b->item[j]
void	insert(t_stack *a, t_stack *b, int j)
{
	if (j <= b->size / 2)
	{
		ps_nrotate(b, j);
		ps_push(a, b);
		ft_printf("pb\n");
		ps_nrrotate(b, j);
	}
	else
	{
		j = b->size - j;
		ps_nrrotate(b, j);
		ps_push(a, b);
		ft_printf("pb\n");
		ps_nrotate(b, j + 1);
	}
}

//the insert sort algorithm
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
				break;
			}
			j++;
		}
		if (j == b->size)
			insert(a, b, j);
		i++;
	}
	ps_npush(b, a, item_quantity + 1);
}
