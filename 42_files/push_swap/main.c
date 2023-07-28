/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:49:56 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/28 06:11:22 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_ac(char str[])
{
	int	ac;
	int	i;

	ac = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			ac++;
			while (str[i] != ' ' && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (ac);
}

void	free_av(char **av, int ac, char *argv[])
{
	int	i;

	if (av == argv + 1)
		return ;
	i = 0;
	while (i < ac)
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int	one_arg(int *ac, char ***av, char *argv[])
{
	if (*ac == 1)
	{
		*ac = init_ac(argv[1]);
		*av = ft_split(argv[1], ' ');
		if (av == NULL)
			return (1);
	}
	return (0);
}

//first step: find the right order for the solutiones
//second step: find the less expansive combination 
//	to change the order of the stack a
//final step: enjoy
int	main(int argc, char *argv[])
{
	char	**av;
	int	ac;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	ac = argc - 1;
	av = argv + 1;
	if (one_arg(&ac, &av, argv))
		return (1);
	a = NULL;
	b = NULL;
	a = init_stack_a(ac, av);
	free_av(av, ac, argv);
	if (a == NULL)
		return (error_exit(a, b));
	b = init_stack_b(a->size);
	if (b == NULL)
		return (error_exit(a, b));
	if (argc > 3)
		//gsort_1(a, b);
		//insert_sort(a, b);
		//quick_sort(a, b, 0, a->size - 1);
		gsort_3(a, b);
	else
		backtrack_sort(a, b);
	exit_free(a, b);
}
