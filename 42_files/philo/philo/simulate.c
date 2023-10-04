/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:47:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/04 15:48:17 by gdornic          ###   ########.fr       */
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
	int			res;

	if (p == NULL)
		return (1);
	res = 1;
	pthread_mutex_lock(p->simulation_mutex);
	if (option == STOP)
		*p->simulation = 0;
	if (*p->simulation == 0)
		res = 0;
	pthread_mutex_unlock(p->simulation_mutex);
	return (res);
}
