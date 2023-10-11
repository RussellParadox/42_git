/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/11 20:03:18 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*watchtower(void *data)
{
	sem_t		*time_sem;

	time_sem = (sem_t *)data;
	synchronize_timer(args);
	while (1)
	{
		//watch eat time
	}
}

void	routine(int args[5], int nb)
{
	t_watcher	*watcher;
	sem_t		*forks_sem;

	forks_sem = sem_open("/forks", O_CREAT, S_IRWXU, args[0]);
	if (forks_sem == SEM_FAILED)
		exit(1);
	watcher = init_watcher(args[1], nb);
	if (watcher == NULL)
		exit(1);
	pthread_create(&watcher->tid, NULL, watchtower, watcher);
	while (args[4] != 0)
	{
		sem_wait(forks_sem);
		state_change(FORK, nb, get_time(CURRENT);
		sem_wait(forks_sem);
		state_change(FORK, nb, get_time(CURRENT);
		state_change(EAT, nb, get_time(CURRENT);
		contact_watcher(watcher);
	}
	pthread_join(watch_tid, NULL);
	sem_close(forks_sem);
	sem_close(time_sem);
}

void	simulation(int args[5])
{
	pid_t	*pid;
	int	i;

	pid = malloc(sizeof(pid_t) * args[0]);
	if (pid == NULL)
		return ;
	i = 0;
	while (i < args[0])
	{
		pid[i] = fork();
		if (pid[i] < 0)
			break ;
		else if (pid[i] == 0)
			routine(args, i + 1);
		i++;
	}
	if (i == args[0])
		wait(NULL);
	i--;
	while (i >= 0)
	{
		kill(pid[i], SIGKILL);
		i--;
	}
}

//args: 0: number of philosophers
//      1: time to die
//      2: time to eat
//      3: time to sleep
//      4: number of time each philosopher must eat
int	main(int argc, char *argv[])
{
	int	args[5];

	if (argc < 5 || argc > 6)
	{
		printf("Arguments must be in sets of 4 or 5.\n");
		return (EXIT_FAILURE);
	}
	if (check_arguments(argv))
		return (EXIT_FAILURE);
	args_init(args, argv);
	simulation(args);
	return (EXIT_SUCCESS);
}
