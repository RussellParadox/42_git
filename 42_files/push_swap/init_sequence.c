/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 10:02:02 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 04:01:07 by gdornic          ###   ########.fr       */
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
