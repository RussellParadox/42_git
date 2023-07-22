/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 07:32:17 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 08:09:54 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_stdin(void)
{
	char	*file;
	char	*line;
	char	*tmp;

	line = get_next_line(0);
	file = ft_strdup("");
	while (line != NULL && file != NULL)
	{
		tmp = file;
		file = ft_strjoin(file, line);
		free(tmp);
		free(line);
		line = get_next_line(0);
	}
	return (file);
}

//check the instruction format
//if the instruction is good, return a pointer to the next instruction
//or to the end of line
//else return NULL
char	*check_instruction(char *instruction, char instruction_set[36])
{
	char	inst[4];
	int		len;

	len = 0;
	while (instruction[len] != '\n' && instruction[len] != '\0')
		len++;
	if (len > 3 || (len != 0 && instruction[len] == '\0') \
	|| (len == 0 && instruction[len] == '\n'))
		return (NULL);
	ft_memcpy(inst, instruction, len);
	inst[len] = '\0';
	if (ft_strnstr(instruction_set, inst, 36) == NULL)
		return (NULL);
	return (instruction + len + 1);
}

//init and check the instructions provided as input
//return the instructions as a string if they're good
//else return NULL
char	*init_instructions(void)
{
	char	*instructions;
	char	*instruction;
	char	instruction_set[36];

	instructions = read_stdin();
	if (instructions == NULL)
		return (NULL);
	ft_memcpy(instruction_set, "sa;sb;ss;pa;pb;ra;rb;rr;rra;rrb;rrr", 36);
	instruction = instructions;
	while (*instruction != '\0')
	{
		instruction = check_instruction(instruction, instruction_set);
		if (instruction == NULL)
		{
			free(instructions);
			return (NULL);
		}
	}
	return (instructions);
}

void	apply_instruction(char inst[4], t_stack *a, t_stack *b)
{
	if (ft_strncmp(inst, "sa", 3) == 0)
		ps_swap(a);
	if (ft_strncmp(inst, "sb", 3) == 0)
		ps_swap(b);
	if (ft_strncmp(inst, "ss", 3) == 0)
		ps_ss(a, b);
	if (ft_strncmp(inst, "pa", 3) == 0)
		ps_push(b, a);
	if (ft_strncmp(inst, "pb", 3) == 0)
		ps_push(a, b);
	if (ft_strncmp(inst, "ra", 3) == 0)
		ps_rotate(a);
	if (ft_strncmp(inst, "rb", 3) == 0)
		ps_rotate(b);
	if (ft_strncmp(inst, "rr", 3) == 0)
		ps_rr(a, b);
	if (ft_strncmp(inst, "rra", 3) == 0)
		ps_rrotate(a);
	if (ft_strncmp(inst, "rrb", 3) == 0)
		ps_rrotate(b);
	if (ft_strncmp(inst, "rrr", 3) == 0)
		ps_rrr(a, b);
}
