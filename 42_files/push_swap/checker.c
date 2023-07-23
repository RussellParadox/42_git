/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 04:57:18 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/23 05:33:56 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*a;
	t_stack	*b;
	char	*instructions;

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
	instructions = init_instructions();
	if (instructions == NULL)
		return (error_exit(a, b));
	apply_instructions(instructions, a, b);
	if (b->size == 0 && is_sorted(a->item, a->size))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(instructions);
	exit_free(a, b);
}
