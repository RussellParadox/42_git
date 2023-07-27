/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tools_high2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:22:25 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/27 23:30:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//do n rr
void	ps_nrr(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_rr(s1, s2);
		ft_printf("rr\n");
		i++;
	}
}

//do n rrr
void	ps_nrrr(t_stack *s1, t_stack *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ps_rrr(s1, s2);
		ft_printf("rrr\n");
		i++;
	}
}
