/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:09:44 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/20 03:28:44 by gdornic          ###   ########.fr       */
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

void	put_wsignal(t_watcher *w, int signal)
{
	sem_wait(w->sem);
	if (w->signal != STOP)
		w->signal = signal;
	sem_post(w->sem);
}

int	get_wsignal(t_watcher *w)
{
	int	wsignal;

	sem_wait(w->sem);
	wsignal = w->signal;
	sem_post(w->sem);
	return (wsignal);
}

void	*watchtower(void *data)
{
	t_watcher	*w;
	long int	reference;
	long int	delay;

	w = (t_watcher *)data;
	reference = get_time(CURRENT);
	delay = 0;
	while (get_wsignal(w) != STOP)
	{
		if (delay > w->threshold)
		{
			state_change(DIE, w->nb, get_time(CURRENT), w);
			sem_post(w->forks_sem);
			break ;
		}
		if (get_wsignal(w) == EAT)
		{
			reference = get_time(CURRENT);
			delay = 0;
			put_wsignal(w, 0);
		}
		usleep(100);
		delay = get_time(CURRENT) - reference;
	}
	return (NULL);
}

t_watcher	*init_watcher(int args[5], int nb)
{
	t_watcher	*w;
	char		name[250];

	w = malloc(sizeof(t_watcher));
	if (w == NULL)
		return (NULL);
	init_name(name, nb);
	sem_unlink(name);
	w->print_sem = sem_open("/print", O_CREAT, S_IRWXU, 1);
	w->forks_sem = sem_open("/forks", O_CREAT, S_IRWXU, args[0]);
	w->forks_pair = sem_open("/forks_pair", O_CREAT, S_IRWXU, 1);
	w->sem = sem_open(name, O_CREAT, S_IRWXU, 1);
	if (w->print_sem == NULL || w->forks_sem == NULL || \
		w->forks_pair == NULL || w->sem == NULL)
	{
		free(w);
		return (NULL);
	}
	w->threshold = args[1];
	w->signal = -1;
	w->nb = nb;
	return (w);
}
