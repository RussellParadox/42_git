/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:10:27 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/25 04:42:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the values of variables pointed by p1 and p2
void	ps_swap(int *p1, int *p2)
{
	int	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//move each element one position higher, the first element become the last
void	ps_rotate(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		ps_swap(s->item[i], s->item[i + 1]);
		i++;
	}
}

//move each element one position lower, the last element become the first
void	ps_rrotate(t_stack *s)
{
	int	i;

	i = s->size - 1;
	while (i > 0)
	{
		ps_swap(s->item[i], s->item[i - 1]);
		i--;
	}
}

//take the top element of s1 and place it on top of s2
void	ps_push(t_stack *s1, t_stack *s2)
{
	s2->item[s2->size] = s1->item[0];
	ps_rotate(s1);
	s1->size -= 1;
	s2->size += 1;
	ps_rrotate(s2);
}
