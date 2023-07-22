/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tools_low.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:10:27 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 04:02:05 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the values of variables pointed by p1 and p2
void	ptr_swap(int *p1, int *p2)
{
	int	tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//swap the two top values of the stack
void	ps_swap(t_stack *s)
{
	if (s->size >= 2)
	{
		ptr_swap(&s->item[0], &s->item[1]);
	}
}

//move each element one position higher, the first element become the last
void	ps_rotate(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size - 1)
	{
		ptr_swap(&s->item[i], &s->item[i + 1]);
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
		ptr_swap(&s->item[i], &s->item[i - 1]);
		i--;
	}
}

//take the top element of s1 and place it on top of s2
void	ps_push(t_stack *s1, t_stack *s2)
{
	if (s1->size == 0)
		return ;
	s2->item[s2->size] = s1->item[0];
	ps_rotate(s1);
	s1->size -= 1;
	s2->size += 1;
	ps_rrotate(s2);
}
