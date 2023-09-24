/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:29:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/24 23:15:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*work(void *data)
{
	t_philosopher	*p;

	p = data;
	printf("thread %ld\n", pthread_self());
	if (p->number == 1)
		p->next->fork = 0;
	else
		printf("thread 2: p->fork: %d\n", p->fork);
}

int	main(int argc, char *argv[])
{
	pthread_t	tid;
	pthread_t	tid2;
	pthread_t	tid3;
	t_philosopher	*p;
	int		args[5];

	args_init(args, argv);
	p = init_philosopher(args);
	pthread_create(&tid, NULL, work, p);
	pthread_join(tid, NULL);
	pthread_create(&tid2, NULL, work, p->next);
	pthread_join(tid2, NULL);
}
