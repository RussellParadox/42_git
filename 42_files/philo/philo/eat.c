/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:00:51 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/02 07:14:10 by gdornic          ###   ########.fr       */
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

int	can_not_eat(t_philosopher *p)
{
	int	res;

	if (p->quantity == 1)
		return (1);
	/*
	if (p->quantity % 2 && (p->number == 1 || p->number == p->quantity))
	{
		if (p->fl_alternate)
		{
			p->fl_alternate = 0;
			wait_for(p, 10);
			return (1);
		}
		else
			p->fl_alternate = 1;
	}
	*/
	//else
	//	p->alternate = 1;
	res = 1;
	while (res)
	{
		if (p->number % 2 == 0)
		{
			pthread_mutex_lock(p->fork_mutex);
			if (p->fork)
			{
				pthread_mutex_lock(p->next->fork_mutex);
				if (p->next->fork)
				{
					p->fork = 0;
					p->next->fork = 0;
					res = 0;
				}
				pthread_mutex_unlock(p->next->fork_mutex);
			}
			pthread_mutex_unlock(p->fork_mutex);
		}
		else
		{
			pthread_mutex_lock(p->next->fork_mutex);
			if (p->next->fork)
			{
				pthread_mutex_lock(p->fork_mutex);
				if (p->fork)
				{
					p->fork = 0;
					p->next->fork = 0;
					res = 0;
				}
				pthread_mutex_unlock(p->fork_mutex);
			}
			pthread_mutex_unlock(p->next->fork_mutex);
		}
		usleep(10);
	}
	return (res);
}

/*
int	can_not_eat(t_philosopher *p)
{
	int	res;

	if (p == NULL)
		return (1);
	pthread_mutex_lock(p->fork_mutex);
	if (p->fork)
	{
		p->fork = 0;
		res = 0;
	}
	else
		res = 1;
	pthread_mutex_unlock(p->fork_mutex);
	if (!res)
	{
		pthread_mutex_lock(p->next->fork_mutex);
		if (p->next->fork)
			p->next->fork = 0;
		else
			res = 2;
		pthread_mutex_unlock(p->next->fork_mutex);
	}
	if (res == 2)
		free_fork(p);
	return (res);
}
*/
