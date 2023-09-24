/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/25 00:28:07 by gdornic          ###   ########.fr       */
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

//state change
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIED 4

//get time
# define INIT 0
# define CURRENT 1

//philosopher hands
# define EMPTY 0
# define FULL 1

typedef struct	s_philosopher
{
	pthread_t	id;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*eat_mutex;
	int		*simulation;
	int		fork;
	int		number;
	int		quantity;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		meals_left;
	long int	prev_eat;
	struct s_philosopher	*next;
}	t_philosopher;

//check arguments
int	check_arguments(char *argv[]);

//args init
void	args_init(int args[5], char *argv[]);

//current time
long int	get_time(int mode);

//state change
int	state_change(long int timestamp, int number, int state);

//init philosopher
t_philosopher	*init_philosopher(int args[5]);

//usleep extend
void	usleep_extend(long int time);

//atomic read
int	atomic_read(int *value, pthread_mutex_t *mutex);

//eat
void	free_fork(t_philosopher *p);
int	can_not_eat(t_philosopher *p);

#endif
