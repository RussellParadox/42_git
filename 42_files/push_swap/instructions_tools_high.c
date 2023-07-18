/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tools_high.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 04:26:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/14 13:18:05 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//do n swap
void	ps_nswap(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_swap(s);
		ft_printf("s%c\n", s->id);
		i++;
	}
}

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

//insert s1->item[0] at place of s2->item[j]
void	insert(t_stack *s1, t_stack *s2, int j)
{
	if (j <= s2->size / 2)
	{
		ps_nrotate(s2, j);
		ps_npush(s1, s2, 1);
		ps_nrrotate(s2, j);
	}
	else
	{
		j = s2->size - j;
		ps_nrrotate(s2, j);
		ps_npush(s1, s2, 1);
		ps_nrotate(s2, j + 1);
	}
}
