/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:29:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/20 11:13:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	(void)data;
	usleep(1000000);
	printf("in thread: %ld\n", get_time(CURRENT));
	return (NULL);
}

int	main(void)
{
	pthread_t	thread;

	if (get_time(INIT))
		return (1);
	usleep(1000000);
	printf("before: %ld\n", get_time(CURRENT));
	if (pthread_create(&thread, NULL, routine, NULL))
		return (1);
	if (pthread_join(thread, NULL))
		return (1);
	printf("after: %ld\n", get_time(CURRENT));
}
