/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:23:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 05:54:29 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord2D	isometric_projection(int x, int y, int z)
{
	t_coord2D	proj;

	proj.x = x * (-1 / sqrt(2)) + y * (1 / sqrt(2)) + z * (0);
	proj.y = x * (1 / sqrt(6)) + y * (1 / sqrt(6)) + z * (-sqrt(2/3));
	return (proj);
}
