/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:30:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/04 18:38:50 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

pthread_mutex_t	*init_simulation_mutex(int mode)
{
	static pthread_mutex_t	*simulation_mutex;

	if (mode == FREE && simulation_mutex != NULL)
	{
		free(simulation_mutex);
		simulation_mutex = NULL;
		return (NULL);
	}
	if (simulation_mutex == NULL)
	{
		simulation_mutex = malloc(sizeof(pthread_mutex_t));
		if (simulation_mutex == NULL)
			return (NULL);
		if (pthread_mutex_init(simulation_mutex, NULL))
			return (NULL);
		return (simulation_mutex);
	}
	return (simulation_mutex);
}

pthread_mutex_t	*init_fork_mutex(int i, int args[5])
{
	static pthread_mutex_t	*mutex;
	int						j;

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
