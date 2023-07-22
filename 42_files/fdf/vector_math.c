/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:37:44 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 09:46:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_double2D	orthogonal_projection(t_int3D coord, t_map *map, t_base3D base)
{
	t_double2D	proj;

	proj.x = (coord.x - map->center.x) * base.e1.x + \
		(coord.y - map->center.y) * base.e2.x + \
		(coord.z - map->center.z) / 10. * base.e3.x;
	proj.y = (coord.x - map->center.x) * base.e1.y + \
		(coord.y - map->center.y) * base.e2.y + \
		(coord.z - map->center.z) / 10. * base.e3.y;
	proj.color = projection_color(coord, map);
	return (proj);
}

t_double2D	vector_projection(t_int3D coord, t_base3D base)
{
	t_double2D	proj;

	proj.x = coord.x * base.e1.x + \
		coord.y * base.e2.x + \
		coord.z * base.e3.x;
	proj.y = coord.x * base.e1.y + \
		coord.y * base.e2.y + \
		coord.z * base.e3.y;
	proj.color = coord.color;
	return (proj);
}

int	signof(double nb)
{
	if (nb < 0)
		return (-1);
	return (1);
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
