/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:38:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/14 12:43:13 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int *stack, long nb, int size)
{
	int	i;

	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	i = 0;
	while (i < size)
	{
		if (stack[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*init_stack_a(int argc, char *argv[])
{
	int	*stack_a;
	int	i;

	if (argc <= 1)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (NULL);
		i++;
	}
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	i = 0;
	while (stack_a != NULL && i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		if (check_duplicate(stack_a, stack_a[i], i))
		{
			free(stack_a);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}
