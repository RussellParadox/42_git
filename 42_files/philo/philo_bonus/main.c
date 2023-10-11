/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/11 01:56:23 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*watchtower(void *data)
{
	long int	
}

void	routine(int args[5], int nb)
{
	sem_t	*forks_sem;
	sem_t	*time_sem;

	forks_sem = sem_open("/forks", O_CREAT, S_IRWXU, args[0]);
	if (forks_sem == SEM_FAILED)
		exit(1);
	time_sem = sem_open("/time", O_CREAT, S_IRWXU, 1);
	if (time_sem == SEM_FAILED)
		exit(1);
	get_time(INIT);
	while (args[4] != 0)
	{
	}
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
