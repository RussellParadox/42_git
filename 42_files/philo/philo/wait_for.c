/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:06:38 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/03 01:14:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//suspend the thread for time ms
//verify p life status
int	wait_for(t_philosopher *p, long int time)
{
	long int	time_delta;

	time_delta = p->prev_eat + p->die_time - get_time(p, CURRENT) - time;
	if (!simulate(p, GET))
		return (1);
	if (time_delta < 0)
	{
		if (!simulate(p, GET))
			return (1);
		usleep((time_delta + time) * 1000);
		end_simulation(p);
		return (1);
	}
	return (usleep(time * 1000));
}
