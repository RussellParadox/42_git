/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:00:51 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/20 04:58:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_fork(t_philosopher *p)
{
	if (p == NULL)
		return ;
	pthread_mutex_lock(p->fork_mutex);
	p->fork = 1;
	pthread_mutex_unlock(p->fork_mutex);
}

int	take_forks(pthread_mutex_t *fork_m1, pthread_mutex_t *fork_m2, \
		int *fork1, int *fork2)
{
	int	res;

	res = 1;
	pthread_mutex_lock(fork_m1);
	if (*fork1)
	{
		pthread_mutex_lock(fork_m2);
		if (*fork2)
		{
			*fork1 = 0;
			*fork2 = 0;
			res = 0;
		}
		pthread_mutex_unlock(fork_m2);
	}
	pthread_mutex_unlock(fork_m1);
	return (res);
}

int	can_not_eat(t_philosopher *p)
{
	int	res;

	if (p->quantity == 1)
		return (1);
	res = 1;
	pthread_mutex_lock(p->hold_mutex);
	while (simulate(p, GET) && \
		get_time(p, CURRENT) - p->prev_eat <= p->die_time && res)
	{
		if (p->number % 2 == 0)
			res = take_forks(p->fork_mutex, p->next->fork_mutex, \
				&p->fork, &p->next->fork);
		else
			res = take_forks(p->next->fork_mutex, p->fork_mutex, \
				&p->next->fork, &p->fork);
		if (!res)
		{
			state_change(get_time(p, CURRENT), p, FORK);
			state_change(get_time(p, CURRENT), p, FORK);
		}
		usleep(100);
	}
	pthread_mutex_unlock(p->hold_mutex);
	return (res);
}
