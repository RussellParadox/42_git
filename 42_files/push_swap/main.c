/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/10 14:23:44 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free allocated memory at ptr only if ptr isn't set to NULL
void	no_null_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

//free the stacks and their content at the end of the program
void	exit_free(t_stack *a, t_stack *b, t_sequence *sequence, t_sequence *output)
{
	no_null_free(a->item);
	no_null_free(a);
	no_null_free(b->item);
	no_null_free(b);
	no_null_free(sequence->move);
	no_null_free(sequence);
	no_null_free(output->move);
	no_null_free(output);
}

//init pointers to NULL
void	null_init(t_stack *a, t_stack *b, t_sequence *sequence, t_sequence *output)
{
	a = NULL;
	b = NULL;
	sequence = NULL;
	output = NULL;
}

int	error_exit(t_stack *a, t_stack *b, t_sequence *sequence, t_sequence *output)
{
	exit_free(a, b, sequence, output);
	ft_printf("Error\n");
	return (1);
}

//first step: find the right order for the solutiones
//second step: find the less expansive combination to change the order of the stack a
//final step: enjoy
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_sequence	*sequence;
	t_sequence	*output;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	sequence = NULL;
	output = NULL;
	a = init_stack_a(argc, argv);
	if (a == NULL)
		return (error_exit(a, b, sequence, output));
	b = init_stack_b(a->size);
	if (b == NULL)
		return (error_exit(a, b, sequence, output));
	sequence = init_sequence(a->size);
	if (sequence == NULL)
		return (error_exit(a, b, sequence, output));
	output = init_sequence(a->size);
	if (output == NULL)
		return (error_exit(a, b, sequence, output));
	backtrack(a, b, sequence, output);
	print_sequence(output);
	exit_free(a, b, sequence, output);
	return (0);
}
