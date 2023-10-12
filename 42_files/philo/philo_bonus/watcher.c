/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:09:44 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/11 22:42:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_name(char name[250], int nb)
{
	int	i;

	memset(name, '\0', 250);
	name[0] = '/';
	i = 1;
	while (nb > 0 && i < 249)
	{
		name[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
}

void	*watchtower(void *data)
{
	t_watcher	*watcher;
	long int	delay;

	watcher = (t_watcher *)data;
	delay = 0;
	while (1)
	{
		if (delay > watcher->threshold)
		{
			free(watcher);
			exit(0);
		}
		sem_wait(watcher->sem);
		if (watcher->signal == 1)
		{
			delay = 0;
			watcher->signal = 0;
		}
		if (watcher->signal == 2)
		{
			sem_post(watcher->sem);
			break ;
		}
		sem_post(watcher->sem);
		usleep(1000);
		delay += 1;
	}
}

t_watcher	*init_watcher(int threshold, int nb)
{
	t_watcher	*watcher;
	char		name[250];

	watcher = malloc(sizeof(t_watcher));
	if (watcher == NULL)
		return (NULL);
	init_name(name, nb);
	watcher->sem = sem_open(name, O_CREAT, S_IRWXU, 1);
	if (watcher->sem == SEM_FAILED)
	{
		free(watcher);
		return (NULL);
	}
	watcher->threshold = threshold;
	watcher->signal = 0;
	watcher->nb = nb;
	return (watcher);
}
