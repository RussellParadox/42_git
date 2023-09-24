/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/25 00:14:55 by gdornic          ###   ########.fr       */
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
		while (can_not_eat(philosopher))
		{
			if (get_time(CURRENT) - philosopher->prev_eat >= philosopher->die_time)
			{
				state_change(get_time(CURRENT), philosopher->number, DIED);
				philosopher->meals_left = 0;
				break ;
			}
		}
		if (philosopher->meals_left == 0)
			break ;
		state_change(get_time(CURRENT), philosopher->number, EAT);
		usleep_extend(philosopher->eat_time);
		free_fork(philosopher);
		free_fork(philosopher->next);
		philosopher->prev_eat = get_time(CURRENT);
		state_change(get_time(CURRENT), philosopher->number, SLEEP);
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
	state_change(0, 0, -1);
	while (i < args[0])
	{
		if (pthread_create(&p->id, NULL, routine, p))
			return ;
		//usleep_extend(10);
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
