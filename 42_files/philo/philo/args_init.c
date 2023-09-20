/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 06:44:39 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/20 07:09:26 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	*nptr_cpy;
	int		res;
	int		sign;

	nptr_cpy = (char *)nptr;
	res = 0;
	sign = 1;
	while ((*nptr_cpy >= '\t' && *nptr_cpy <= '\r') || (*nptr_cpy == ' '))
		nptr_cpy++;
	if (*nptr_cpy == '+' || *nptr_cpy == '-')
	{
		if (*nptr_cpy == '-')
			sign = -1;
		nptr_cpy++;
	}
	while (ft_isdigit(*nptr_cpy))
	{
		res = res * 10 + (*nptr_cpy - '0');
		nptr_cpy++;
	}
	return (sign * res);
}

void	args_init(int args[5], char *argv[])
{
	args[0] = ft_atoi(argv[1]);
	args[1] = ft_atoi(argv[2]);
	args[2] = ft_atoi(argv[3]);
	args[3] = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		args[4] = ft_atoi(argv[5]);
	else
		args[4] = -1;
}
