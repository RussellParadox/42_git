/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:22:46 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/05 12:31:38 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	child_routine(void)
{
	while (1)
	{
		printf("coucou\n");
		usleep(100000);
	}
	exit(0);
}

int	main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (1);
	if (pid == 0)
		child_routine();
	usleep(1000000);
	printf("kill return: %d\n", kill(pid, SIGKILL));
}
