/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:54:39 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/04 19:06:25 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	new_philosopher_cut(t_philosopher *new, int i, int args[5])
{
	if (new == NULL)
		return (1);
	new->fork_mutex = init_fork_mutex(i, args);
	if (new->fork_mutex == NULL)
		return (1);
	new->hold_mutex = init_hold_mutex(GET);
	if (new->hold_mutex == NULL)
		return (1);
	new->simulation = init_simulation(GET);
	if (new->simulation == NULL)
		return (1);
	new->ready_mutex = init_ready_mutex(GET);
	if (new->ready_mutex == NULL)
		return (1);
	new->print_mutex = init_print_mutex(GET);
	if (new->print_mutex == NULL)
		return (1);
	new->ready = init_ready(GET);
	if (new->ready == NULL)
		return (1);
	new->simulation_mutex = init_simulation_mutex(GET);
	if (new->simulation_mutex == NULL)
		return (1);
	return (0);
}

t_philosopher	*new_philosopher(int i, int args[5])
{
	t_philosopher	*new;

	new = init_philosophers(i, args);
	if (new_philosopher_cut(new, i, args))
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
	int				i;

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
