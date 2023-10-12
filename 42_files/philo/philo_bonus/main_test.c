/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:22:46 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/12 16:05:25 by gdornic          ###   ########.fr       */
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
	exit(0);
}

void	test_routine(void)
{
	while (1)
	{
	}
}

int	main(void)
{
	t_watcher	*watcher;
	pid_t		pid;

	pid = fork();
	if (pid == 0)
	{
		watcher = init_watcher(200, 513);
		pthread_create(&watcher->tid, NULL, child_routine, watcher);
		pthread_join(watcher->tid, NULL);
		printf("coucou");
	}
	sem_unlink("/315");
	wait(NULL);
}
