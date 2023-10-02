/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 05:35:07 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/02 05:50:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold_philo(t_philosopher *p)
{
	if (p->number == p->quantity)
	{
		pthread_mutex_lock(p->ready_mutex);
		*p->ready = 1;
		pthread_mutex_unlock(p->ready_mutex);
		return ;
	}
	pthread_mutex_lock(p->hold_mutex);
	if (p->number != 1)
	{
		pthread_mutex_unlock(p->hold_mutex);
		return ;
	}
	while (1)
	{
		pthread_mutex_lock(p->ready_mutex);
		if (*p->ready)
		{
			pthread_mutex_unlock(p->ready_mutex);
			break ;
		}
		pthread_mutex_unlock(p->ready_mutex);
	}
	pthread_mutex_unlock(p->hold_mutex);
}
