/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:03:55 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/27 23:08:00 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_min(int x1, int x2)
{
	return ((x1 <= x2) * x1 + (x1 > x2) * x2);
}

int	int_dist(int x1, int x2)
{
	return ((x1 <= x2) * (x2 - x1) + (x2 < x1) * (x1 - x2));
}
