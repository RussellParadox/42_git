/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tools_high_silent.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 04:26:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 15:01:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//do n swap
void	ps_snswap(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_swap(s);
		i++;
	}
}

//do n push
void	ps_snpush(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_push(s1, s2);
		i++;
	}
}

//do n rotations
void	ps_snrotate(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_rotate(s);
		i++;
	}
}

//do n reverse rotations
void	ps_snrrotate(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_rrotate(s);
		i++;
	}
}

//do n ss
void	ps_snss(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_ss(s1, s2);
		i++;
	}
}
