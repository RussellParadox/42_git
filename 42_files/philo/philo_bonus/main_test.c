/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:22:46 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/11 21:00:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*child_routine(void *data)
{
	t_watcher	*watcher;

	watcher = (t_watcher *)data;
	sem_wait(watcher->sem);
	printf("%ld\n", get_time(INIT));
	sem_post(watcher->sem);
}

int	main(void)
{
	t_watcher	*watcher;

	watcher = init_watcher(200, 513);
	pthread_create(&watcher->tid, NULL, child_routine, watcher);
	usleep(10000);
	sem_wait(watcher->sem);
	printf("%ld\n", get_time(CURRENT));
	sem_post(watcher->sem);
	pthread_join(watcher->tid, NULL);
	sem_unlink("/315");
}
