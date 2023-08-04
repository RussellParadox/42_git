/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/04 16:27:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//first step: find the right order for the solutiones
//second step: find the less expansive combination 
//	to change the order of the stack a
//final step: enjoy
int	main(int argc, char *argv[])
{
	char	**av;
	int		ac;
	t_stack	*s[2];

	if (argc < 2)
		return (0);
	ac = argc - 1;
	av = argv + 1;
	if (one_arg(&ac, &av, argv))
		return (1);
	s[1] = NULL;
	s[0] = init_stack_a(ac, av);
	free_av(av, ac, argv);
	if (s[0] == NULL)
		return (error_exit(s[0], s[1]));
	s[1] = init_stack_b(s[0]->size);
	if (s[1] == NULL)
		return (error_exit(s[0], s[1]));
	if (is_rotate_sorted(s[0]))
		rotate_sort(s[0]);
	else if (s[0]->size > 5)
		gsort_3(s[0], s[1]);
	else
		backtrack_sort(s[0], s[1]);
	exit_free(s[0], s[1]);
}
