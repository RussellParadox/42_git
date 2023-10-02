/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:29:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/01 07:27:04 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	delay;

void	*work(void *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%ld\n", time.tv_sec * 1000000 + time.tv_usec - delay);
	(void)data;
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	*thread;
	struct timeval	time;
	int		thread_qt;
	int		i;

	if (argc != 2 || check_arguments(argv))
		return (0);
	thread_qt = ft_atoi(argv[1]);
	thread = malloc(sizeof(pthread_t) * thread_qt);
	if (thread == NULL)
		return (1);
	printf("0\n");
	gettimeofday(&time, NULL);
	delay = time.tv_sec * 1000000 + time.tv_usec;
	i = 0;
	while (i < thread_qt)
	{
		pthread_create(&thread[i], NULL, work, NULL);
		i++;
	}
	i = 0;
	while (i < thread_qt)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
