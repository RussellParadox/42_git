/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:00:49 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/12 22:54:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	state_change(int state, int nb, long int timestamp)
{
	static sem_t	*print_sem;

	if (print_sem == NULL)
		print_sem = sem_open("/print", O_CREAT, S_IRWXU, 1);
	sem_wait(print_sem);
	if (state == FORK)
		printf("%ld %d has taken a fork\n", timestamp, nb);
	if (state == EAT)
		printf("%ld %d is eating\n", timestamp, nb);
	if (state == SLEEP)
		printf("%ld %d is sleeping\n", timestamp, nb);
	if (state == THINK)
		printf("%ld %d is thinking\n", timestamp, nb);
	if (state == DIE)
	{
		printf("%ld %d died\n", timestamp, nb);
		return ;
	}
	sem_post(print_sem);
}
