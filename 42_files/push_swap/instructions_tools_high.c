/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tools_high.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 04:26:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/24 04:22:09 by gdornic          ###   ########.fr       */
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

//do n ss
void	ps_nss(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_ss(s1, s2);
		ft_printf("ss\n");
		i++;
	}
}
