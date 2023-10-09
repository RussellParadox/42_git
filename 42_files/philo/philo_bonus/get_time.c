/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:14:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/30 21:15:37 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	time_in_ms(struct timeval time)
{
	return (time.tv_sec * 1000. + time.tv_usec / 1000.);
}

//mode: 0: init get_time
//	1: init philosopher time
//      2: get current time
//      3: end get_time
long int	get_time(t_philosopher *p, int mode)
{
	struct timeval		time;

	if (gettimeofday(&time, NULL))
	{
		printf("Gettimeofday malfunction.\n");
		return (-1);
	}
	if (mode == INIT_P)
		p->time_start = time_in_ms(time);
	return (time_in_ms(time) - p->time_start);
}
