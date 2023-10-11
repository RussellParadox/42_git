/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:22:46 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/11 02:05:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*child_routine(void *data)
{
	usleep(1000000);
	printf("%ld\n",  get_time(CURRENT));
}

int	main(void)
{
	pthread_t	tid;

	printf("%ld\n", get_time(INIT));
	usleep(1000000);
	printf("%ld\n",  get_time(CURRENT));
	pthread_create(&tid, NULL, child_routine, NULL);
	pthread_join(tid, NULL);
}
