/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:26:59 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 04:29:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
