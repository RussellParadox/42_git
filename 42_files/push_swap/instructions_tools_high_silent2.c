/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tools_high_silent2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:22:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 15:02:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//do n rr
void	ps_snrr(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_rr(s1, s2);
		i++;
	}
}

//do n rrr
void	ps_snrrr(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_rrr(s1, s2);
		i++;
	}
}
