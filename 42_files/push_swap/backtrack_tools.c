/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:16:19 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 03:58:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//apply move on a and/or b
void	make_move(int move, t_stack *a, t_stack *b)
{
	if (move == 1)
		ps_swap(a);
	else if (move == 2)
		ps_swap(b);
	else if (move == 3)
		ps_ss(a, b);
	else if (move == 4)
		ps_push(b, a);
	else if (move == 5)
		ps_push(a, b);
	else if (move == 6)
		ps_rotate(a);
	else if (move == 7)
		ps_rotate(b);
	else if (move == 8)
		ps_rr(a, b);
	else if (move == 9)
		ps_rrotate(a);
	else if (move == 10)
		ps_rrotate(b);
	else if (move == 11)
		ps_rrr(a, b);
}

//apply the reverse move on a and/or b
void	unmake_move(int move, t_stack *a, t_stack *b)
{
	if (move == 1)
		ps_swap(a);
	else if (move == 2)
		ps_swap(b);
	else if (move == 3)
		ps_ss(a, b);
	else if (move == 4)
		ps_push(a, b);
	else if (move == 5)
		ps_push(b, a);
	else if (move == 6)
		ps_rrotate(a);
	else if (move == 7)
		ps_rrotate(b);
	else if (move == 8)
		ps_rrr(a, b);
	else if (move == 9)
		ps_rotate(a);
	else if (move == 10)
		ps_rotate(b);
	else if (move == 11)
		ps_rr(a, b);
}

//return true if m1 and m2 are symmetric moves
int	symmetric_move(int m1, int m2)
{
	if (m1 == 0 || m2 == 0)
		return (1);
	if (m1 == 1 && m2 == 1)
		return (1);
	if (m1 == 2 && m2 == 2)
		return (1);
	if (m1 == 3 && m2 == 3)
		return (1);
	if ((m1 == 4 && m2 == 5) || (m2 == 4 && m1 == 5))
		return (1);
	if ((m1 == 6 && m2 == 9) || (m2 == 6 && m1 == 9))
		return (1);
	if ((m1 == 8 && m2 == 11) || (m2 == 8 && m1 == 11))
		return (1);
	if ((m1 == 7 && m2 == 10) || (m2 == 7 && m1 == 10))
		return (1);
	return (0);
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
