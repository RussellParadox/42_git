/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/23 00:02:44 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*next_fork;

	philosopher = (t_philosopher *)data;
	//printf("starting philosopher %d\n", philosopher->number);
	next_fork = philosopher->next->fork;
	while (philosopher->meals_left != 0)
	{
		state_change(get_time(CURRENT), philosopher->number, THINK);
		if (pthread_mutex_lock(philosopher->fork) \
		|| pthread_mutex_lock(next_fork))
			return ((void *)1);
		/*
		if (get_time(CURRENT) - philosopher->prev_eat >= philosopher->die_time)
		{
			state_change(get_time(CURRENT), philosopher->number, DIED);
			break ;
		}
		*/
		philosopher->prev_eat = get_time(CURRENT);
		state_change(get_time(CURRENT), philosopher->number, EAT);
		//usleep_extend(philosopher->eat_time);
		state_change(get_time(CURRENT), philosopher->number, SLEEP);
		//usleep_extend(philosopher->sleep_time);
		pthread_mutex_unlock(philosopher->fork);
		pthread_mutex_unlock(next_fork);
		//philosopher->meals_left--;
	}
	return (NULL);
}

void	start_philosophy(t_philosopher *philosopher, int args[5])
{
	t_philosopher	*p;
	int	i;

	i = 0;
	p = philosopher;
	state_change(-1, 0, 0);
	while (i < args[0])
	{
		if (pthread_create(&p->id, NULL, routine, p))
			return ;
		usleep_extend(10);
		//pthread_detach(p->id);
		p = p->next;
		i++;
	}
}

//args: 0: number of philosophers
//      1: time to die
//      2: time to eat
//      3: time to sleep
//      4: number of time each philosopher must eat
int	main(int argc, char *argv[])
{
	static t_philosopher	*philosopher;
	t_philosopher		*p;
	int			args[5];

	if (argc < 5 || argc > 6)
	{
		printf("Arguments must be in sets of 4 or 5.\n");
		return (EXIT_FAILURE);
	}
	if (check_arguments(argv))
		return (EXIT_FAILURE);
	args_init(args, argv);
	if (get_time(INIT))
		return (EXIT_FAILURE);
	philosopher = init_philosopher(args);
	if (philosopher == NULL)
		return (EXIT_FAILURE);
	p = philosopher;
	printf("philosopher %d meal left %d\n", p->number, p->meals_left);
	p = p->next;
	while (p != philosopher)
	{
		printf("philosopher %d meal left %d\n", p->number, p->meals_left);
		p = p->next;
	}
	start_philosophy(philosopher, args);
}
