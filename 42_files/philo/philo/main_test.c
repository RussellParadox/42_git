/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:29:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/23 17:55:40 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*work(void *data)
{
	static int	value;

	if (value == 0)
		value = 3;
	printf("thread %ld, value: %d, value address: %p\n", pthread_self(), value, &value);
}

int	main(void)
{
	pthread_t	tid;
	pthread_t	tid2;
	pthread_t	tid3;

	pthread_create(&tid, NULL, work, NULL);
	usleep(100000);
	pthread_create(&tid2, NULL, work, NULL);
	usleep(100000);
	pthread_create(&tid3, NULL, work, NULL);
}
