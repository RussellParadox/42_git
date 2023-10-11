/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:33:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/11 01:38:02 by gdornic          ###   ########.fr       */
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

//get time
# define INIT 0
# define CURRENT 1
long int	get_time(int mode);

//check arguments
int	check_arguments(char *argv[]);

//args init
int	ft_atoi(const char *nptr);
void	args_init(int args[5], char *argv[]);

#endif