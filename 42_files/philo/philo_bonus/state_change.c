/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:00:49 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/20 03:27:14 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	die(long int timestamp, int nb, t_watcher *w)
{
	printf("%ld %d died\n", timestamp, nb);
	put_wsignal(w, STOP);
	usleep(1000000);
}

void	state_change(int state, int nb, long int timestamp, t_watcher *w)
{
	sem_t		*print_sem;
	long int	delay;

	if (get_wsignal(w) == STOP)
		return ;
	print_sem = w->print_sem;
	delay = get_time(CURRENT);
	sem_wait(print_sem);
	delay = get_time(CURRENT) - delay;
	if (delay >= 2)
	{
		put_wsignal(w, STOP);
		state = -1;
	}
	else if (state == FORK)
		printf("%ld %d has taken a fork\n", timestamp, nb);
	else if (state == EAT)
		printf("%ld %d is eating\n", timestamp, nb);
	else if (state == SLEEP)
		printf("%ld %d is sleeping\n", timestamp, nb);
	else if (state == THINK)
		printf("%ld %d is thinking\n", timestamp, nb);
	else if (state == DIE)
		die(timestamp, nb, w);
	sem_post(print_sem);
}
