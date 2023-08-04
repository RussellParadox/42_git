/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 04:57:18 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/04 16:25:25 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_result(t_stack *a, t_stack *b)
{
	if (b->size == 0 && is_sorted(a->item, a->size))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	apply_instructions(char *instructions, t_stack *a, t_stack *b)
{
	char	inst[4];
	int		len;

	while (*instructions != '\0')
	{
		len = 0;
		while (instructions[len] != '\n')
			len++;
		ft_memcpy(inst, instructions, len);
		inst[len] = '\0';
		apply_instruction(inst, a, b);
		instructions += len + 1;
	}
}

//a little program that check a sequence of push_swap instructions
//print OK if the instructions sort the given stack
//print KO if the instructions don't sort the given stack
//print Error if an error occurs
int	main(int argc, char *argv[])
{
	char	*instructions;
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
	instructions = init_instructions();
	if (instructions == NULL)
		return (error_exit(s[0], s[1]));
	apply_instructions(instructions, s[0], s[1]);
	print_result(s[0], s[1]);
	free(instructions);
	exit_free(s[0], s[1]);
}
