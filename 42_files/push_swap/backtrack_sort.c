/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:26:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 08:12:51 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//take the quantity of numbers in input and
//init the sequence with the worst possible complexity
//for push_swap moves on the insert sort algorithm
t_sequence	*init_sequence(int size)
{
	t_sequence	*s;
	int			ps_complexity;
	int			i;

	s = (t_sequence *)malloc(sizeof(t_sequence));
	if (s != NULL)
	{
		ps_complexity = size * size + 1;
		s->move = (int *)malloc(sizeof(int) * ps_complexity);
		if (s->move == NULL)
		{
			free(s);
			return (NULL);
		}
		i = 0;
		while (i < ps_complexity)
		{
			s->move[i] = 0;
			i++;
		}
		s->depth = 0;
		s->max_depth = ps_complexity - 1;
		s->rotation_max = size;
	}
	return (s);
}

void	backtrack_sort(t_stack *a, t_stack *b)
{
	t_sequence	*sequence;
	t_sequence	*output;

	sequence = init_sequence(a->size);
	if (sequence == NULL)
		return ;
	output = init_sequence(a->size);
	if (output == NULL)
	{
		free(sequence->move);
		free(sequence);
		return ;
	}
	backtrack(a, b, sequence, output);
	print_sequence(output);
	free(sequence->move);
	free(sequence);
	free(output->move);
	free(output);
}
