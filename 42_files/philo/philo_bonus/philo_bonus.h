/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/12 15:52:41 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>

typedef struct	s_watcher
{
	pthread_t	tid;
	sem_t		*sem;
	long int	threshold;
	int		signal;
	int		nb;
}	t_watcher;

//watcher
# define STOP 2
t_watcher	*init_watcher(int threshold, int nb);
void	contact_watchtower(t_watcher *w, int signal);
void	*watchtower(void *data);

//get time
# define INIT 0
# define CURRENT 1
long int	get_time(int mode);

//state change
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4
void	state_change(int state, int nb, long int timestamp);

//check arguments
int	check_arguments(char *argv[]);

//args init
int	ft_atoi(const char *nptr);
void	args_init(int args[5], char *argv[]);

#endif
