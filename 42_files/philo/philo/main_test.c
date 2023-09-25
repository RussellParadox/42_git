/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 04:29:33 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/25 11:54:20 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*static_malloc_test(void)
{
	int	*all;

	all = malloc(sizeof(int) * 10000000);
	return (all);
}

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
	t_philosopher	*p;
	int		*test;
	int		args[5];

	//test = malloc(sizeof(int));
	test = static_malloc_test();
}
