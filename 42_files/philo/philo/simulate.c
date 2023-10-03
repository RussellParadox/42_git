/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:47:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/03 00:46:36 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*end_simulation(t_philosopher *p)
{
	if (simulate(p, GET))
	{
		state_change(get_time(p, CURRENT), p, DIED);
		simulate(p, STOP);
	}
	return (NULL);
}

int	simulate(t_philosopher *p, int option)
{
	static pthread_mutex_t	mutex;
	static int		init_mutex;
	int			res;

	res = 1;
	if (init_mutex == 0)
	{
		init_mutex = 1;
		pthread_mutex_init(&mutex, NULL);
	}
	if (p == NULL)
		return (1);
	pthread_mutex_lock(&mutex);
	if (option == STOP)
		*p->simulation = 0;
	if (*p->simulation == 0)
		res = 0;
	pthread_mutex_unlock(&mutex);
	return (res);
}
