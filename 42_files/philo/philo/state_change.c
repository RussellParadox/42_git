/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:11:01 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/29 07:23:51 by gdornic          ###   ########.fr       */
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
	int			number;

	if (timestamp == -1)
		return (1);
	if (p == NULL)
		return (0);
	number = p->number;
	pthread_mutex_lock(p->print_mutex);
	if (simulate(p, GET) && state == FORK)
		printf("%ld %d has taken a fork\n", timestamp, number);
	if (simulate(p, GET) && state == EAT)
		printf("%ld %d is eating       \n", timestamp, number);
	if (simulate(p, GET) && state == SLEEP)
		printf("%ld %d is sleeping     \n", timestamp, number);
	if (simulate(p, GET) && state == THINK)
		printf("%ld %d is thinking     \n", timestamp, number);
	if (simulate(p, GET) && state == DIED)
		printf("%ld %d died            \n", timestamp, number);
	pthread_mutex_unlock(p->print_mutex);
	return (0);
}
