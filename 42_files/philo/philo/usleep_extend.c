/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:03:21 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/22 23:29:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//usleep with more than 1000000 mircroseconds
//time is in milliseconds
void	usleep_extend(long int time)
{
	long int	rest;

	time = time * 1000;
	rest = time % 999999;
	time = time / 999999;
	while (time > 0)
	{
		usleep(999999);
		time--;
	}
	usleep(rest);
}
