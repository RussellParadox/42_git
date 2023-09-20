/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/20 11:05:36 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosopher(t_philosopher *philosopher, int i, int args[5])
{
	philosopher->number = i;
	philosopher->die_time = args[1];
	philosopher->eat_time = args[2];
	philosopher->sleep_time = args[3];
	philosopher->meals_left = args[4];
	philosopher->prev_eat = get_time(CURRENT);
}

void	*routine(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	while (philosopher->meals_left != 0)
	{
		
	}
}

void	start_philosophy(int args[5])
{
	t_philosopher	*philosopher;
	int	i;

	philosopher = malloc(sizeof(t_philosopher) * args[0]);
	if (philosopher == NULL)
		return ;
	i = 0;
	while (i < args[0])
	{
		init_philosopher(&philosopher[i], i, args);
		if (pthread_create(philosopher[i]->id, NULL, routine, &i))
			return ;
		i++;
	}
	while (i > 0)
	{
		
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
	if (get_time(INIT))
		return (EXIT_FAILURE);
	start_philosophy(args);
}
