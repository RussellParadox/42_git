/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:14:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/29 00:03:29 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	time_in_ms(struct timeval time)
{
	return (time.tv_sec * 1000. + time.tv_usec / 1000. + 0.5);
}

//mode: 0: init get_time
//	1: init philosopher time
//      2: get current time
//      3: end get_time
long int	get_time(t_philosopher *p, int mode)
{
	static long int		*time_start;
	struct timeval		time;

	if (time_start != NULL && mode == END)
	{
		free(time_start);
		time_start = NULL;
		return (0);
	}
	if (p != NULL && mode == INIT)
	{
		time_start = malloc(sizeof(long int) * p->quantity);
		if (time_start == NULL)
			return (-1);
	}
	if (gettimeofday(&time, NULL))
	{
		printf("Gettimeofday malfunction.\n");
		return (-1);
	}
	if (mode == INIT_P)
		time_start[p->number - 1] = time_in_ms(time);
	return (time_in_ms(time) - time_start[p->number - 1]);
}
