/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:26:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/04 16:26:50 by gdornic          ###   ########.fr       */
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
