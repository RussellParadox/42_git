/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/29 07:19:02 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philosopher	*p;

	p = (t_philosopher *)data;
	state_change(0, p, THINK);
	p->prev_eat = get_time(p, INIT_P);
	while (p->meals_left != 0)
	{
		if (can_not_eat(p))
		{
			if (!simulate(p, GET) || p->prev_eat + p->die_time - get_time(p, CURRENT) < 0)
				return (end_simulation(p));
		}
		else
		{
			if (!simulate(p, GET))
				return (NULL);
			p->prev_eat = get_time(p, CURRENT);
			state_change(p->prev_eat, p, EAT);
			if (wait_for(p, p->eat_time))
				return (NULL);
			free_fork(p);
			free_fork(p->next);
			state_change(get_time(p, CURRENT), p, SLEEP);
			if (wait_for(p, p->sleep_time))
				return (NULL);
			state_change(get_time(p, CURRENT), p, THINK);
			p->meals_left--;
		}
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
	state_change(0, NULL, -1);
	simulate(NULL, GET);
	get_time(p, INIT);
	while (i < args[0])
	{
		if (p->number % 2 == 0 && pthread_create(&p->id, NULL, routine, p))
			return ;
		//usleep(1000);
		p = p->next;
		i++;
	}
	p = philosopher;
	i = 0;
	while (i < args[0])
	{
		if (p->number % 2 != 0 && pthread_create(&p->id, NULL, routine, p))
			return ;
		//usleep(1000);
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
	get_time(NULL, END);
}

void	free_init(void)
{
	init_print_mutex(FREE);
	init_eat_mutex(FREE);
	init_ready_mutex(FREE);
	init_simulation(FREE);
	init_ready(FREE);
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
