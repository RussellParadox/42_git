/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/04 05:12:38 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//print stacks for testing tools
void	ps_print(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("_ _\n");
	while (i < a->size || i < b->size)
	{
		if (i < a->size)
			ft_printf("%d", a->item[i]);
		else
			ft_printf(" ");
		ft_printf(" ");
		if (i < b->size)
			ft_printf("%d", b->item[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("_ _\n");
	ft_printf("a b\n");
}

//free allocated memory at ptr only if ptr isn't set to NULL
void	no_null_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

//free the stacks and their content at the end of the program
void	exit_free(t_stack *a, t_stack *b)
{
	no_null_free(a->item);
	no_null_free(a);
	no_null_free(b->item);
	no_null_free(b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack_a(argc, argv);
	if (a == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	b = init_stack_b(a->size);
	if (b == NULL)
	{
		exit_free(a, b);
		ft_printf("Error\n");
		return (1);
	}
	ps_print(a, b);
	quick_sort(a, b, 0, a->size - 1);
	//insert_sort(a, b);
	ps_print(a, b);
	exit_free(a, b);
	return (0);
}
