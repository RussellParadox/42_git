/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:22:46 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/11 17:15:57 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*child_routine(void *data)
{
	usleep(1000000);
	printf("%ld\n",  get_time(CURRENT));
	exit(0);
}

int	main(void)
{
	pthread_t	pid;

	printf("%ld\n", get_time(INIT));
	usleep(1000000);
	printf("%ld\n",  get_time(CURRENT));
	pid = fork();
	if (pid > 0)
		child_routine(NULL);
}
