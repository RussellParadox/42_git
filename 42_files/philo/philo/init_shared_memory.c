/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shared_memory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:44:34 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/04 18:45:34 by gdornic          ###   ########.fr       */
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
