/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:38:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 12:41:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int *stack, long nb, int size)
{
	int	i;

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
	int		i;
	size_t	int_len;
	long	max;

	max = INT_MAX;
	int_len = 1;
	while (max != 0)
	{
		int_len += 1;
		max /= 10;
	}
	if ((str[0] == '-' && ft_strlen(str) > int_len + 1) \
	|| (str[0] != '-' && ft_strlen(str) > int_len))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !(str[i] == '-' && ft_isdigit(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	*init_item_a(int argc, char **argv)
{
	int	*stack_a;
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (NULL);
		i++;
	}
	stack_a = (int *)malloc((argc) * sizeof(int));
	if (stack_a == NULL)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		stack_a[i] = ft_atoi(argv[i]);
		if (check_duplicate(stack_a, stack_a[i], i))
		{
			free(stack_a);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}

t_stack	*init_stack_a(int argc, char *argv[])
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (a != NULL)
	{
		a->item = init_item_a(argc, argv);
		if (a->item == NULL)
		{
			free(a);
			return (NULL);
		}
		a->size = argc;
		a->id = 'a';
	}
	return (a);
}

t_stack	*init_stack_b(int size)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (b != NULL)
	{
		b->item = (int *)malloc(size * sizeof(int));
		if (b->item == NULL)
		{
			free(b);
			return (NULL);
		}
		b->size = 0;
		b->id = 'b';
	}
	return (b);
}
