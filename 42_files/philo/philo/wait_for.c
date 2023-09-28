/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:06:38 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/29 00:02:30 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//suspend the thread for time ms
//verify p life status
int	wait_for(t_philosopher *p, long int time)
{
	long int	time_delta;

	time_delta = p->prev_eat + p->die_time - get_time(p, CURRENT) - time;
	if (time_delta < 0)
	{
		usleep_extend(time_delta + time);
		end_simulation(p);
		return (1);
	}
	return (usleep_extend(time));
}
