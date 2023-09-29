/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:14:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/29 07:10:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	time_in_ms(struct timeval time)
{
	return (time.tv_sec * 1000. + time.tv_usec / 1000.);
}

//mode: 0: init time
//      1: get current time
long int	get_time(t_philosopher *p, int mode)
{
	static long int		time_start;
	struct timeval		time;
	long int		return_time;

	(void)p;
	if (gettimeofday(&time, NULL))
	{
		printf("Gettimeofday malfunction.\n");
		return (-1);
	}
	if (mode == INIT)
		time_start = time_in_ms(time);
	return_time = time_in_ms(time) - time_start;
	return (return_time);
}
