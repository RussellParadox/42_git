/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 04:57:18 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 05:49:11 by gdornic          ###   ########.fr       */
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

char	*init_instructions(void)
{
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *b;
	char	*instructions;

	if (argc < 2)
		return (0);
	a = NULL;
	a = init_stack_a(argc, argv);
	if (a == NULL)
		return (error_exit(a, b));
	b = init_stack_b(a->size);
	if (b == NULL)
		return (error_exit(a, b));
	instructions = init_instructions();
	if (instructions == NULL)
		return (error_exit(a, b));
}
