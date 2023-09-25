/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/25 16:20:31 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	philosopher->prev_eat = get_time(CURRENT);
	while (philosopher->meals_left != 0 && simulate(philosopher))
	{
		state_change(get_time(CURRENT), philosopher, THINK);
		while (can_not_eat(philosopher))
		{
			if (simulate(philosopher) || get_time(CURRENT) - philosopher->prev_eat >= philosopher->die_time)
			{
				state_change(get_time(CURRENT), philosopher, DIED);
				philosopher->meals_left = 0;
				simulate(philosopher);
				break ;
			}
		}
		if (philosopher->meals_left == 0)
			break ;
		state_change(get_time(CURRENT), philosopher, EAT);
		usleep_extend(philosopher->eat_time);
		free_fork(philosopher);
		free_fork(philosopher->next);
		philosopher->prev_eat = get_time(CURRENT);
		state_change(get_time(CURRENT), philosopher, SLEEP);
		usleep_extend(philosopher->sleep_time);
		philosopher->meals_left--;
	}
	return (NULL);
}

void	start_philosophy(t_philosopher *philosopher, int args[5])
{
	t_philosopher	*p;
	int	i;

	state_change(-1, 0, 0);
	p = philosopher;
	i = 0;
	get_time(INIT);
	state_change(0, NULL, -1);
	simulate(NULL);
	while (i < args[0])
	{
		if (pthread_create(&p->id, NULL, routine, p))
			return ;
		p = p->next;
		i++;
	}
	p = philosopher;
	i = 0;
	while (i < args[0])
	{
		pthread_join(p->id, NULL);
		p = p->next;
		i++;
	}
}

void	free_init(void)
{
	init_eat_mutex(FREE);
	init_simulation(FREE);
	init_philosophers(-1, NULL);
	init_fork_mutex(-1, NULL);
}

//args: 0: number of philosophers
//      1: time to die
//      2: time to eat
//      3: time to sleep
//      4: number of time each philosopher must eat
int	main(int argc, char *argv[])
{
	t_philosopher	*philosopher;
	int			args[5];

	if (argc < 5 || argc > 6)
	{
		printf("Arguments must be in sets of 4 or 5.\n");
		return (EXIT_FAILURE);
	}
	if (check_arguments(argv))
		return (EXIT_FAILURE);
	args_init(args, argv);
	philosopher = init_philosopher(args);
	if (philosopher == NULL)
	{
		free_init();
		return (EXIT_FAILURE);
	}
	start_philosophy(philosopher, args);
	free_init();
	return (EXIT_SUCCESS);
}
