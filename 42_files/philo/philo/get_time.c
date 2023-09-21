/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:14:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/21 17:51:22 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	time_in_ms(struct timeval time)
{
	return (time.tv_sec * 1000. + time.tv_usec / 1000.);
}

//mode: 0: init time
//      1: get current time
long int	get_time(int mode)
{
	static long int	time_start;
	static pthread_mutex_t	*mutex;
	struct timeval	time;

	if (mutex == NULL)
	{
		mutex = malloc(sizeof(pthread_mutex_t));
		if (mutex == NULL)
			return (-1);
		pthread_mutex_init(mutex, NULL);
	}
	if (pthread_mutex_lock(mutex))
		return (-1);
	if (gettimeofday(&time, NULL))
	{
		printf("Gettimeofday malfunction.\n");
		return (-1);
	}
	if (mode == INIT)
		time_start = time_in_ms(time);
	if (pthread_mutex_unlock(mutex))
		return (-1);
	return (time_in_ms(time) - time_start);
}
