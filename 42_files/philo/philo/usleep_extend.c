/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:03:21 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/28 23:15:25 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define USLEEP_LIMIT 999999

//usleep with more than 999999 microseconds
//time is in milliseconds
int	usleep_extend(long int time)
{
	long int	rest;

	time = time * 1000;
	rest = time % USLEEP_LIMIT;
	time = time / USLEEP_LIMIT;
	while (time > 0)
	{
		if (usleep(USLEEP_LIMIT))
			return (1);
		time--;
	}
	return (usleep(rest));
}
