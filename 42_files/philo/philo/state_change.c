/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:11:01 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/25 16:17:41 by gdornic          ###   ########.fr       */
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
int	state_change(long int timestamp, t_philosopher *p, int state)
{
	static pthread_mutex_t	mutex;
	static int		init_mutex;
	int			number;

	if (timestamp == -1)
		return (1);
	if (init_mutex == 0)
	{
		init_mutex = 1;
		pthread_mutex_init(&mutex, NULL);
	}
	if (p == NULL)
		return (0);
	if (!simulate(p))
		return (0);
	number = p->number;
	if (pthread_mutex_lock(&mutex))
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
	pthread_mutex_unlock(&mutex);
	return (0);
}
