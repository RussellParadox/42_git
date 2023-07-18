/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 10:32:38 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/13 19:15:49 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//return true if the sequence isn't a solution, in that case we're going backwards in depth -1
int	reject_sequence(t_sequence *sequence, t_stack *b)
{
	int	depth;

	depth = sequence->depth;
	if (b->size != 0)
		return (1);
	if (depth == sequence->max_depth)
		return (1);
	if (depth > 1)
	{
		if (symmetric_move(sequence->move[depth], sequence->move[depth - 1]))
			return (1);
	}
	return (0);
}

//return true if the sequence is a solution, in that case the new maximum depth is set to the depth of the solution -1 and we're going backwards in depth -1 to search a better solution
int	accept_sequence(t_stack *a, t_stack *b)
{
	int	i;
	int	n;
	int	*item;

	if (b->size != 0)
		return (0);
	n = a->size - 1;
	item = a->item;
	i = 0;
	while (i < n)
	{
		if (item[i] > item[i + 1])
			return (0);
		i++;
	}
	return (1);
}

//apply move on a and/or b and save it in sequence, the depth become depth + 1
void	sequence_explore(t_stack *a, t_stack *b, t_sequence *sequence, int move)
{
	static int	rotation_count = 0;

	if (rotation_count >= sequence->rotation_max)
		move = 0;
	if (move == 1 && a->size == 0)
		move = 0;
	if (move == 2 && b->size == 0)
		move = 0;
	if (move == 3 && (a->size == 0 || b->size == 0))
		move = 0;
	if (move == 4 && b->size == 0)
		move = 0;
	if (move == 5 && a->size == 0)
		move = 0;
	if (move == 6 && sequence->move[sequence->depth] == 6)
		rotation_count += 1;
	else if (move == 7 && sequence->move[sequence->depth] == 7)
		rotation_count += 1;
	else if (move == 8 && sequence->move[sequence->depth] == 8)
		rotation_count += 1;
	else if (move == 9 && sequence->move[sequence->depth] == 9)
		rotation_count += 1;
	else if (move == 10 && sequence->move[sequence->depth] == 10)
		rotation_count += 1;
	else if (move == 11 && sequence->move[sequence->depth] == 11)
		rotation_count += 1;
	else
		rotation_count = 0;
	sequence->depth += 1;
	make_move(move, a, b);
	sequence->move[sequence->depth] = move;
}

//go back in depth by applying the reverse move of the last move in sequence
void	sequence_unexplore(t_stack *a, t_stack *b, t_sequence *sequence)
{
	unmake_move(sequence->move[sequence->depth], a, b);
	sequence->depth -= 1;
}

int	accept_sequence2(t_stack *a, t_stack *b, t_sequence *sequence)
{
	int	i;

	i = 0;
	while (i <= sequence->depth)
	{
		make_move(sequence->move[i], a, b);
		i++;
	}
	if (b->size != 0)
	{
		i = sequence->depth;
		while (i >= 0)
		{
			unmake_move(sequence->move[i], a, b);
			i--;
		}
		return (0);
	}
	i = 0;
	while (i < a->size - 1)
	{
		if (a->item[i] > a->item[i + 1])
		{
			i = sequence->depth;
			while (i >= 0)
			{
				unmake_move(sequence->move[i], a, b);
				i--;
			}
			return (0);
		}
		i++;
	}
	i = sequence->depth;
	while (i >= 0)
	{
		unmake_move(sequence->move[i], a, b);
		i--;
	}
	return (1);
}	

void	backtrack(t_stack *a, t_stack *b, t_sequence *sequence, t_sequence *output)
{
	int	i;

	if (reject_sequence(sequence, b))
	{
		return;
	}
	//if (accept_sequence2(a, b, sequence))
	if (accept_sequence(a, b))
	{
		improve_output(sequence, output);
		return;
	}
	i = 1;
	while (i <= 11)
	{
		if (i != 3 && i != 8 && i != 11)
		{
			sequence_explore(a, b, sequence, i);
			backtrack(a, b, sequence, output);
			sequence_unexplore(a, b, sequence);
		}
		i++;
	}
}
