/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:00:51 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/23 18:43:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(pthread_mutex_t *fork_mutex, pthread_mutex_t *next_fork_mutex, \
		int *fork, int *next_fork)
{
	pthread_mutex_lock(fork_mutex);
	*fork = 1;
	pthread_mutex_unlock(fork_mutex);
	pthread_mutex_lock(next_fork_mutex);
	*next_fork = 1;
	pthread_mutex_unlock(next_fork_mutex);
}

int	can_not_eat(pthread_mutex_t *fork_mutex, pthread_mutex_t *next_fork_mutex, \
		int *fork, int *next_fork)
{
	static int	
	int	res;

	pthread_mutex_lock(fork_mutex);
	if (*fork)
	{
		*fork = 0;
		res = 0;
	}
	else
		res = 1;
	pthread_mutex_unlock(fork_mutex);
	pthread_mutex_lock(next_fork_mutex);
	if (*next_fork)
		*next_fork = 0;
	else
		res = 1;
	pthread_mutex_unlock(next_fork_mutex);
	if (res)
		free_forks(fork_mutex, next_fork_mutex, fork, next_fork);
	return (res);
}
