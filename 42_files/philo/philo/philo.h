/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/20 04:53:22 by gdornic          ###   ########.fr       */
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
# define INIT_P 1
# define CURRENT 2
# define END 3

//init functions
# define GET 0
# define FREE 1

//simulate
# define STOP 1

//synchronize
# define ADD 1

typedef struct s_philosopher
{
	pthread_t				id;
	pthread_mutex_t			*fork_mutex;
	pthread_mutex_t			*hold_mutex;
	pthread_mutex_t			*ready_mutex;
	pthread_mutex_t			*print_mutex;
	pthread_mutex_t			*simulation_mutex;
	int						*simulation;
	int						*ready;
	int						fork;
	int						number;
	int						quantity;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	int						meals_left;
	int						fl_alternate;
	int						alternate;
	long int				prev_eat;
	long int				time_start;
	struct s_philosopher	*next;
}	t_philosopher;

//check arguments
int				check_arguments(char *argv[]);

//args init
int				ft_atoi(const char *nptr);
void			args_init(int args[5], char *argv[]);

//get time
long int		get_time(t_philosopher *p, int mode);

//state change
int				state_change(long int timestamp, t_philosopher *p, int state);

//init philosopher
t_philosopher	*init_philosophers(int i, int args[5]);
t_philosopher	*init_philosopher(int args[5]);

//init mutex
pthread_mutex_t	*init_simulation_mutex(int mode);
pthread_mutex_t	*init_print_mutex(int mode);
pthread_mutex_t	*init_ready_mutex(int mode);
pthread_mutex_t	*init_hold_mutex(int mode);
pthread_mutex_t	*init_fork_mutex(int i, int args[5]);

//free init
void			free_init(void);

//init shared memory
int				*init_ready(int mode);
int				*init_simulation(int mode);

//usleep extend
int				usleep_extend(long int time);

//atomic read
int				atomic_read(int *value, pthread_mutex_t *mutex);

//eat
void			free_fork(t_philosopher *p);
int				can_not_eat(t_philosopher *p);

//simulate
void			*end_simulation(t_philosopher *p);
int				simulate(t_philosopher *p, int option);

//wait for
int				wait_for(t_philosopher *p, long int time);

//hold philo
void			hold_philo(t_philosopher *p);

#endif
