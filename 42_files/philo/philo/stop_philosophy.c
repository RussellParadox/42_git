/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_philosophy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:12:29 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/20 10:26:47 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_philosophy(int decision)
{
	static int	*over;

	if (over == NULL)
	{
		over = malloc(sizeof(int));
		if (over == NULL)
			return (1);
	}
	if (!*over)
		*over = vote;
	return (*over);
}
