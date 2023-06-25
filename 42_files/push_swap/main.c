/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/25 04:45:34 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	a = (t_stack *)malloc(sizeof(t_stack));
	a->item = init_stack_a(argc, argv);
	a->size = argc - 1;
	if (a->item == NULL)
	{
		free(a);
		ft_printf("Error\n");
		return (1);
	}
	b = (t_stack *)malloc(sizeof(t_stack));
	b->item = (int *)malloc((a->size) * sizeof(int));
	b->size = 0;
	if (b->item == NULL)
	{
		free(a->item);
		free(b);
		ft_printf("Error\n");
		return (1);
	}
	free(a->item);
	free(b->item);
	free(a);
	free(b);
}
