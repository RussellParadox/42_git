/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:10:27 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/14 19:42:13 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the 2 first element of the stack
void	ps_swap(int *stack)
{
	int	tmp;

	tmp = *stack;
	*stack = *(stack + 1);
	*(stack + 1) = tmp;
}
