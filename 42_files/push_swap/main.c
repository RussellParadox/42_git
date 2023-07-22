/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 05:34:29 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//first step: find the right order for the solutiones
//second step: find the less expansive combination 
//	to change the order of the stack a
//final step: enjoy
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	a = init_stack_a(argc, argv);
	if (a == NULL)
		return (error_exit(a, b));
	b = init_stack_b(a->size);
	if (b == NULL)
		return (error_exit(a, b));
	if (argc > 6)
		quick_sort(a, b, 0, a->size - 1);
	else
		backtrack_sort(a, b);
	exit_free(a, b);
	return (0);
}
