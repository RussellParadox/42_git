/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:29:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/01 02:40:39 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define WAIT_TIME 10000

int	main()
{
	struct timeval	time;
	long int	delay;

	gettimeofday(&time, NULL);
	delay = time.tv_sec * 1000000 + time.tv_usec;
	//usleep(WAIT_TIME);
	usleep_extend(WAIT_TIME);
	gettimeofday(&time, NULL);
	delay = time.tv_sec * 1000000 + time.tv_usec - delay;
	printf("delay: %ld micro-seconds\n", delay);
	printf("error: %ld micro-seconds\n", delay - WAIT_TIME * 1000);
}
