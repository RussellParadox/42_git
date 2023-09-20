/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 07:11:01 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/20 08:35:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//timestamp: since Epoch
//
//state: 0: has taken a fork
//       1: is eating
//       2: is sleeping
//       3: is thinking
//       4: died
int	state_change(long int timestamp, int philosopher, int state)
{
	if (timestamp == -1)
		return (1);
	if (state == FORK)
		printf("%ld %d has taken a fork\n", timestamp, philosopher);
	if (state == EAT)
		printf("%ld %d is eating\n", timestamp, philosopher);
	if (state == SLEEP)
		printf("%ld %d is sleeping\n", timestamp, philosopher);
	if (state == THINK)
		printf("%ld %d is thinking\n", timestamp, philosopher);
	if (state == DIED)
		printf("%ld %d died\n", timestamp, philosopher);
	return (0);
}
