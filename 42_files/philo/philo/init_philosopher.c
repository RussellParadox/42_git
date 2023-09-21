/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:54:39 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/21 17:30:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*new_philosopher(pthread_mutex_t *mutex, int i, int args[5])
{
	static t_philosopher	*new;

	new = malloc(sizeof(t_philosopher));
	if (new == NULL)
		return (NULL);
	new->fork = &mutex[i];
	new->number = i + 1;
	new->quantity = args[0];
	new->die_time = args[1];
	new->eat_time = args[2];
	new->sleep_time = args[3];
	new->meals_left = args[4];
	new->prev_eat = get_time(CURRENT);
	return (new);
}

t_philosopher	*init_philosopher(int args[5])
{
	static pthread_mutex_t	*mutex;
	t_philosopher	*philosopher;
	t_philosopher	*first;
	int		i;

	mutex = malloc(sizeof(pthread_mutex_t) * args[0]);
	if (mutex == NULL)
		return (NULL);
	i = 0;
	while (i < args[0])
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	philosopher = new_philosopher(mutex, 0, args);
	first = philosopher;
	i = 1;
	while (i < args[0])
	{
		philosopher->next = new_philosopher(mutex, i, args);
		philosopher = philosopher->next;
		i++;
	}
	philosopher->next = first;
	return (first);
}
