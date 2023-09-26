/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:47:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/26 00:11:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulate(t_philosopher *p, int option)
{
	static pthread_mutex_t	mutex;
	static int		init_mutex;
	int			res;

	res = 1;
	if (init_mutex == 0)
	{
		init_mutex = 1;
		pthread_mutex_init(&mutex, NULL);
	}
	if (p == NULL)
		return (1);
	pthread_mutex_lock(&mutex);
	if (option)
		*p->simulation = 0;
	if (*p->simulation == 0)
		res = 0;
	pthread_mutex_unlock(&mutex);
	return (res);
}
