/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:54:39 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/02 05:51:29 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*init_simulation(int mode)
{
	static int	*simulation;

	if (mode == FREE && simulation != NULL)
	{
		free(simulation);
		simulation = NULL;
		return (NULL);
	}
	if (simulation == NULL)
	{
		simulation = malloc(sizeof(int));
		if (simulation != NULL)
			*simulation = 1;
		return (simulation);
	}
	return (simulation);
}

pthread_mutex_t	*init_print_mutex(int mode)
{
	static pthread_mutex_t	*print_mutex;

	if (mode == FREE && print_mutex != NULL)
	{
		free(print_mutex);
		print_mutex = NULL;
		return (NULL);
	}
	if (print_mutex == NULL)
	{
		print_mutex = malloc(sizeof(pthread_mutex_t));
		if (print_mutex == NULL)
			return (NULL);
		if (pthread_mutex_init(print_mutex, NULL))
			return (NULL);
		return (print_mutex);
	}
	return (print_mutex);
}

pthread_mutex_t	*init_ready_mutex(int mode)
{
	static pthread_mutex_t	*ready_mutex;

	if (mode == FREE && ready_mutex != NULL)
	{
		free(ready_mutex);
		ready_mutex = NULL;
		return (NULL);
	}
	if (ready_mutex == NULL)
	{
		ready_mutex = malloc(sizeof(pthread_mutex_t));
		if (ready_mutex == NULL)
			return (NULL);
		if (pthread_mutex_init(ready_mutex, NULL))
			return (NULL);
		return (ready_mutex);
	}
	return (ready_mutex);
}

pthread_mutex_t	*init_hold_mutex(int mode)
{
	static pthread_mutex_t	*hold_mutex;

	if (mode == FREE && hold_mutex != NULL)
	{
		free(hold_mutex);
		hold_mutex = NULL;
		return (NULL);
	}
	if (hold_mutex == NULL)
	{
		hold_mutex = malloc(sizeof(pthread_mutex_t));
		if (hold_mutex == NULL)
			return (NULL);
		if (pthread_mutex_init(hold_mutex, NULL))
			return (NULL);
		return (hold_mutex);
	}
	return (hold_mutex);
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

int	*init_ready(int mode)
{
	static int	*ready;

	if (mode == FREE)
	{
		if (ready != NULL)
			free(ready);
		ready = NULL;
	}
	if (ready == NULL)
	{
		ready = malloc(sizeof(int));
		if (ready == NULL)
			return (NULL);
		*ready = 0;
	}
	return (ready);
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
	new->hold_mutex = init_hold_mutex(GET);
	if (new->hold_mutex == NULL)
		return (NULL);
	new->simulation = init_simulation(GET);
	if (new->simulation == NULL)
		return (NULL);
	new->ready_mutex = init_ready_mutex(GET);
	if (new->ready_mutex == NULL)
		return (NULL);
	new->print_mutex = init_print_mutex(GET);
	if (new->print_mutex == NULL)
		return (NULL);
	new->ready = init_ready(GET);
	if (new->ready == NULL)
		return (NULL);
	new->fork = 1;
	new->number = i + 1;
	new->quantity = args[0];
	new->die_time = args[1];
	new->eat_time = args[2];
	new->sleep_time = args[3];
	new->meals_left = args[4];
	if (new->number % 2)
		new->alternate = 1;
	else
		new->alternate = 0;
	if (new->number == args[0])
		new->fl_alternate = 1;
	else
		new->fl_alternate = 0;
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
