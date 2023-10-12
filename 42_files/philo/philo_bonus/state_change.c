/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:00:49 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/12 15:02:30 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	state_change(int state, int nb, long int time)
{
	static sem_t	*print_sem;

	if (print_sem == NULL)
		print_sem = sem_open("/print", O_CREAT, S_IRWXU, 1);
	sem_wait(print_sem);
	if (state == FORK)
		printf("
	sem_post(print_sem);
}
