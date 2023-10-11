/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:14:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/11 01:31:19 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

double	time_in_ms(struct timeval time)
{
	return (time.tv_sec * 1000. + time.tv_usec / 1000.);
}

long int	get_time(int mode)
{
	static int		time_start;
	struct timeval		time;

	if (gettimeofday(&time, NULL))
	{
		printf("Gettimeofday malfunction.\n");
		return (-1);
	}
	if (mode == INIT)
		time_start = time_in_ms(time);
	return (time_in_ms(time) - time_start);
}
