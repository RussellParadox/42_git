/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_tools_low2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:43:55 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/10 08:47:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ss(t_stack *a, t_stack *b)
{
	ps_swap(a);
	ps_swap(b);
}

void	ps_rr(t_stack *a, t_stack *b)
{
	ps_rotate(a);
	ps_rotate(b);
}

void	ps_rrr(t_stack *a, t_stack *b)
{
	ps_rrotate(a);
	ps_rrotate(b);
}
