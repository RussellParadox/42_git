/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/21 17:52:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	while (philosopher->meals_left != 0)
	{
		state_change(get_time(CURRENT), philosopher->number, THINK);
		if (pthread_mutex_lock(philosopher->fork) \
		|| pthread_mutex_lock(philosopher->next->fork))
			return ((void *)1);
		pthread_mutex_unlock(philosopher->fork);
		pthread_mutex_unlock(philosopher->next->fork);
		if (get_time(CURRENT) - philosopher->prev_eat >= philosopher->die_time)
		{
			state_change(get_time(CURRENT), philosopher->number, DIED);
			break ;
		}
		philosopher->prev_eat = get_time(CURRENT);
		state_change(get_time(CURRENT), philosopher->number, EAT);
		usleep(philosopher->eat_time * 1000);
		state_change(get_time(CURRENT), philosopher->number, SLEEP);
		usleep(philosopher->sleep_time * 1000);
		philosopher->meals_left--;
	}
	return (NULL);
}

void	start_philosophy(t_philosopher *philosopher, int args[5])
{
	t_philosopher	*p;
	int	i;

	i = 0;
	p = philosopher;
	while (i < args[0])
	{
		if (pthread_create(&p->id, NULL, routine, p))
			return ;
		pthread_detach(p->id);
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
	int	args[5];

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
	start_philosophy(philosopher, args);
}
