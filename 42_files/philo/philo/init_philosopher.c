/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:54:39 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/25 15:14:00 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*init_simulation(void)
{
	static int	*simulation;

	if (simulation == NULL)
		simulation = malloc(sizeof(int));
	return (simulation);
}

pthread_mutex_t	*init_eat_mutex(void)
{
	static pthread_mutex_t	*eat_mutex;

	if (eat_mutex == NULL)
	{
		eat_mutex = malloc(sizeof(pthread_mutex_t));
		if (eat_mutex == NULL)
			return (NULL);
		if (pthread_mutex_init(eat_mutex, NULL))
			return (NULL);
	}
	return (eat_mutex);
}

t_philosopher	*init_philosophers(int i, int args[5])
{
	static t_philosopher	*philosopher;

	if (i == -1 && philosopher != NULL)
	{
		free(philosopher);
		philosopher = NULL;
		return (NULL);
	}
	if (philosopher == NULL)
	{
		philosopher = malloc(sizeof(t_philosopher) * args[0]);
		if (philosopher == NULL)
			return (NULL);
	}
	return (&philosopher[i]);
}

pthread_mutex_t	*init_fork_mutex(int i, int args[5])
{
	static pthread_mutex_t	*mutex;
	int			j;

	if (i == -1 && mutex != NULL)
	{
		free(mutex);
		mutex = NULL;
		return (NULL);
	}
	if (mutex == NULL)
	{
		mutex = malloc(sizeof(pthread_mutex_t) * args[0]);
		if (mutex == NULL)
			return (NULL);
		j = 0;
		while (j < args[0])
		{
			if (pthread_mutex_init(&mutex[j], NULL))
				return (NULL);
			j++;
		}
	}
	return (&mutex[i]);
}

t_philosopher	*new_philosopher(int i, int args[5])
{
	t_philosopher	*new;

	new = init_philosophers(i, args);
	if (new == NULL)
		return (NULL);
	new->fork_mutex = init_fork_mutex(i, args);
	if (new->fork_mutex == NULL)
		return (NULL);
	new->eat_mutex = init_eat_mutex();
	if (new->eat_mutex == NULL)
		return (NULL);
	new->simulation = init_simulation();
	if (new->simulation == NULL)
		return (NULL);
	new->fork = 1;
	new->number = i + 1;
	new->quantity = args[0];
	new->die_time = args[1];
	new->eat_time = args[2];
	new->sleep_time = args[3];
	new->meals_left = args[4];
	return (new);
}

t_philosopher	*init_philosopher(int args[5])
{
	t_philosopher	*philosopher;
	t_philosopher	*first;
	int		i;

	philosopher = new_philosopher(0, args);
	if (philosopher == NULL)
		return (NULL);
	first = philosopher;
	i = 1;
	while (i < args[0])
	{
		philosopher->next = new_philosopher(i, args);
		philosopher = philosopher->next;
		if (philosopher == NULL)
			return (NULL);
		i++;
	}
	philosopher->next = first;
	return (first);
}
