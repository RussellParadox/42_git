/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:54:39 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/25 00:36:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_eat_mutex(void)
{
	static pthread_mutex_t	*eat_mutex;

	if (eat_mutex == NULL)
	{
		eat_mutex = malloc(sizeof(pthread_mutex_t));
		if (eat_mutex == NULL)
			return (NULL);
		pthread_mutex_init(eat_mutex, NULL);
	}
	return (eat_mutex);
}

t_philosopher	*new_philosopher(pthread_mutex_t *mutex, int i, int args[5])
{
	static t_philosopher	*new;

	new = malloc(sizeof(t_philosopher));
	if (new == NULL)
		return (NULL);
	new->fork_mutex = &mutex[i];
	new->eat_mutex = init_eat_mutex();
	if (init_eat_mutex == NULL)
		return (NULL);
	new->fork = 1;
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
