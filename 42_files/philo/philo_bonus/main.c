/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/19 04:45:36 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(int args[5], int nb, pid_t *pid)
{
	t_watcher	*w;
	sem_t		*forks_sem;
	sem_t		*forks_pair;

	forks_sem = sem_open("/forks", O_CREAT, S_IRWXU, args[0]);
	if (forks_sem == SEM_FAILED)
		exit(1);
	forks_pair = sem_open("/forks_pair", O_CREAT, S_IRWXU, 1);
	if (forks_pair == SEM_FAILED)
		exit(1);
	w = init_watcher(args[1], nb);
	if (w == NULL)
		exit(1);
	w->print_sem = sem_open("/print", O_CREAT, S_IRWXU, 1);
	if (w->print_sem == SEM_FAILED)
		exit(1);
	get_time(INIT);
	state_change(THINK, nb, get_time(CURRENT), w);
	pthread_create(&w->tid, NULL, watchtower, w);
	while (args[4] != 0 && get_wsignal(w) != STOP)
	{
		sem_wait(forks_pair);
		sem_wait(forks_sem);
		state_change(FORK, nb, get_time(CURRENT), w);
		sem_wait(forks_sem);
		sem_post(forks_pair);
		put_wsignal(w, EAT);
		state_change(FORK, nb, get_time(CURRENT), w);
		state_change(EAT, nb, get_time(CURRENT), w);
		usleep(args[2] * 1000);
		sem_post(forks_sem);
		sem_post(forks_sem);
		state_change(SLEEP, nb, get_time(CURRENT), w);
		usleep(args[3] * 1000);
		state_change(THINK, nb, get_time(CURRENT), w);
		if (args[4] != -1)
			args[4]--;
	}
	put_wsignal(w, STOP);
	sem_close(forks_sem);
	pthread_join(w->tid, NULL);
	sem_close(w->sem);
	sem_close(w->print_sem);
	free(w);
	free(pid);
	exit(0);
}

void	simulation(int args[5])
{
	pid_t	*pid;
	int	i;

	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/forks_pair");
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
			routine(args, i + 1, pid);
		i++;
	}
	//if (i == args[0])
	//	waitpid(-1, NULL, 0);
	i--;
	while (i >= 0)
	{
		waitpid(pid[i], NULL, 0);
		//kill(pid[i], SIGKILL);
		i--;
	}
	free(pid);
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
