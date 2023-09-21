/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:11:01 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/21 17:50:48 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//timestamp: since Epoch
//
//state: 0: has taken a fork
//       1: is eating
//       2: is sleeping
//       3: is thinking
//       4: died
int	state_change(long int timestamp, int number, int state)
{
	static pthread_mutex_t	*mutex;

	if (timestamp == -1)
		return (1);
	if (mutex == NULL)
	{
		mutex = malloc(sizeof(pthread_mutex_t));
		if (mutex == NULL)
			return (1);
		pthread_mutex_init(mutex, NULL);
	}
	if (pthread_mutex_lock(mutex))
		return (1);
	if (state == FORK)
		printf("%ld %d has taken a fork\n", timestamp, number);
	if (state == EAT)
		printf("%ld %d is eating\n", timestamp, number);
	if (state == SLEEP)
		printf("%ld %d is sleeping\n", timestamp, number);
	if (state == THINK)
		printf("%ld %d is thinking\n", timestamp, number);
	if (state == DIED)
		printf("%ld %d died\n", timestamp, number);
	pthread_mutex_unlock(mutex);
	return (0);
}
