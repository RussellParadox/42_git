/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:16:19 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/10 14:31:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//apply move on a and/or b
void	make_move(int move, t_stack *a, t_stack *b)
{
	if (move == 1)
		ps_swap(a);
	if (move == 2)
		ps_swap(b);
	if (move == 3)
		ps_ss(a, b);
	if (move == 4)
		ps_push(b, a);
	if (move == 5)
		ps_push(a, b);
	if (move == 6)
		ps_rotate(a);
	if (move == 7)
		ps_rotate(b);
	if (move == 8)
		ps_rr(a, b);
	if (move == 9)
		ps_rrotate(a);
	if (move == 10)
		ps_rrotate(b);
	if (move == 11)
		ps_rrr(a, b);
}

//apply the reverse move on a and/or b
void	unmake_move(int move, t_stack *a, t_stack *b)
{
	if (move == 1)
		ps_swap(a);
	if (move == 2)
		ps_swap(b);
	if (move == 3)
		ps_ss(a, b);
	if (move == 4)
		ps_push(a, b);
	if (move == 5)
		ps_push(b, a);
	if (move == 6)
		ps_rrotate(a);
	if (move == 7)
		ps_rrotate(b);
	if (move == 8)
		ps_rrr(a, b);
	if (move == 9)
		ps_rotate(a);
	if (move == 10)
		ps_rotate(b);
	if (move == 11)
		ps_rr(a, b);
}

//copy sequence in output and adjust the max depth for the search of solutions
void	improve_output(t_sequence *sequence, t_sequence *output)
{
	int	i;
	int	depth;

	depth = sequence->depth;
	i = 0;
	while (i <= depth)
	{
		output->move[i] = sequence->move[i];
		i++;
	}
	sequence->max_depth = depth;
	output->max_depth = depth;
}
