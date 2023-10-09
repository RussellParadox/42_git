/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 06:35:49 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/05 11:31:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//answer the question: is c not a figure ?
int	is_not_figure(char c)
{
	if ('0' <= c && c <= '9')
		return (0);
	return (1);
}

//check if each argument is an unsigned integer
int	check_arguments(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (is_not_figure(argv[i][j]))
			{
				printf("Arguments must be unsigned integers.\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
