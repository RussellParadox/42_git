/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:37:44 by gdornic           #+#    #+#             */
/*   Updated: 2023/05/29 15:20:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	scalar_product(t_double3D v1, t_double3D v2)
{
	double	result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (result);
}

t_double3D	rotation(t_double3D v1, t_double3D u, double dtheta)
{
	t_double3D	v2;
	double		c;
	double		s;

	c = cos(dtheta);
	s = sin(dtheta);
	v2.x = (c + (1 - c) * pow(u.x, 2)) * v1.x + \
		((1 - c) * u.y * u.x - s * u.z) * v1.y + \
		((1 - c) * u.z * u.x + s * u.y) * v1.z;
	v2.y = ((1 - c) * u.x * u.y + s * u.z) * v1.x + \
		(c + (1 - c) * pow(u.y, 2)) * v1.y + \
		((1 - c) * u.z * u.y - s * u.x) * v1.z;
	v2.z = ((1 - c) * u.x * u.z - s * u.y) * v1.x + \
		((1 - c) * u.y * u.z + s * u.x) * v1.y + \
		(c + (1 - c) * pow(u.z, 2)) * v1.z;
	return (v2);
}

//u is the direction vector of the rotation axis
//dtheta is the angle variation around the axis
void	base_rotation(t_base3D *base, t_double3D u, double dtheta)
{
	base->e1 = rotation(base->e1, u, dtheta);
	base->e2 = rotation(base->e2, u, dtheta);
	base->e3 = rotation(base->e3, u, dtheta);
}
