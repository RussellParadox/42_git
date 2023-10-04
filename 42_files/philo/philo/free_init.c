/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:11:49 by gdornic           #+#    #+#             */
/*   Updated: 2023/10/04 19:12:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_init(void)
{
	init_print_mutex(FREE);
	init_hold_mutex(FREE);
	init_ready_mutex(FREE);
	init_simulation(FREE);
	init_ready(FREE);
	init_simulation_mutex(FREE);
	init_philosophers(-1, NULL);
	init_fork_mutex(-1, NULL);
}
