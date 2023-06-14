/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/14 20:04:43 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->stack = init_stack_a(argc, argv);
	if (stack_a == NULL)
	{
		ft_printf("Error\n");
		return (1);
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d: %d\n", i, stack_a[i]);
		i++;
	}
	ps_swap(stack_a);
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d: %d\n", i, stack_a[i]);
		i++;
	}
	stack_b = (int *)malloc((argc - 1) * sizeof(int));
	if (stack_b == NULL)
	{
		free(stack_a);
		ft_printf("Error\n");
		return (1);
	}
	free(stack_a);
	free(stack_b);
}
