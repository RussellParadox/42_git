/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/02 09:30:56 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	delay;

void	*routine(void *data)
{
	t_philosopher	*p;
	//struct timeval	time;
	int		essais;

	p = (t_philosopher *)data;
	//gettimeofday(&time, NULL);
	//printf("start: delay in thread %d: %ld micro-seconds\n", p->number, time.tv_sec * 1000000 + time.tv_usec - delay);
	hold_philo(p);
	//gettimeofday(&time, NULL);
	//printf("after hold: delay in thread %d: %ld micro-seconds\n", p->number, time.tv_sec * 1000000 + time.tv_usec - delay);
	//return (NULL);
	p->prev_eat = get_time(p, INIT_P);
	state_change(get_time(p, CURRENT), p, THINK);
	essais = 0;
	while (p->meals_left != 0)
	{
		if (can_not_eat(p))
		{
			if (!simulate(p, GET) || p->prev_eat + p->die_time - get_time(p, CURRENT) < 0)
				return (end_simulation(p));
		}
		else
		{
			//printf("%d essais avant de pouvoir manger: %d\n", p->number, essais);
			essais = 0;
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
		essais++;
	}
	return (NULL);
}

void	start_philosophy(t_philosopher *philosopher, int args[5])
{
	t_philosopher	*p;
	struct timeval	time;
	int	i;

	state_change(-1, 0, 0);
	p = philosopher;
	i = 0;
	state_change(0, NULL, -1);
	simulate(NULL, GET);
	gettimeofday(&time, NULL);
	delay = time.tv_sec * 1000000 + time.tv_usec;
	while (i < args[0])
	{
		if (pthread_create(&p->id, NULL, routine, p))
			return ;
		usleep(10000);
		i++;
		p = p->next;
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
	init_print_mutex(FREE);
	init_hold_mutex(FREE);
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
