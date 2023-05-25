/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:26:07 by gdornic           #+#    #+#             */
/*   Updated: 2023/05/24 14:00:08 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_double3D	rotation(t_double3D v1, t_double3D u, double dtheta)
{
	t_double3D v2;
	double c;
	double s;

	c = cos(dtheta);
	s = sin(dtheta);
	v2.x = (c + (1 - c) * pow(u.x, 2)) * v1.x + ((1 - c) * u.y * u.x - s * u.z) * v1.y + ((1 - c) * u.z * u.x + s * u.y) * v1.z;
	v2.y = ((1 - c) * u.x * u.y + s * u.z) * v1.x + (c + (1 - c) * pow(u.y, 2)) * v1.y + ((1 - c) * u.z * u.y - s * u.x) * v1.z;
	v2.z = ((1 - c) * u.x * u.z - s * u.y) * v1.x + ((1 - c) * u.y * u.z + s * u.x) * v1.y + (c + (1 - c) * pow(u.z, 2)) * v1.z;
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

t_mlx	*init_mlx(t_settings *settings)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->instance = mlx_init();
	mlx->win = mlx_new_window(mlx->instance, settings->max.x, settings->max.y, "fdf");
	return (mlx);
}

void	make_offset(t_settings *settings, t_map *map)
{
	settings->offset.x = 0.5 * settings->max.x;
	settings->offset.y = 0.5 * settings->max.y;
}

t_settings	*settings_init(t_double2D max, t_map *map)
{
	t_settings	*settings;
	t_double2D	proj_xymax;
	t_double2D	proj_apex;
	t_double2D	proj_abyss;

	settings = (t_settings *)malloc(sizeof(t_settings));
	settings->max.x = max.x;
	settings->max.y = max.y;
	settings->border.x = settings->max.x / 15.;
	settings->border.y = settings->max.y / 15.;
	map->center = (t_double3D){.x = map->max.x / 2., .y = map->max.y / 2., .z = (map->apex.z + map->abyss.z) / 2.};
	settings->map_base.e1 = (t_double3D){1, 0, 0}; 
	settings->map_base.e2 = (t_double3D){0, 1, 0}; 
	settings->map_base.e3 = (t_double3D){0, 0, 1}; 
	base_rotation(&(settings->map_base), (t_double3D){0, 0, 1}, -3 * M_PI / 4.);
	base_rotation(&(settings->map_base), (t_double3D){1, 0, 0}, M_PI-acos(1/sqrt(3)));
	settings->color_profile = map->color_profile;
	proj_xymax = orthogonal_projection((t_int3D){map->max.x, map->max.y, 0}, map, settings->map_base);
	proj_apex = orthogonal_projection((t_int3D){map->apex.x, map->apex.y, map->apex.z}, map, settings->map_base);
	proj_abyss = orthogonal_projection((t_int3D){map->abyss.x, map->abyss.y, map->abyss.z}, map, settings->map_base);
	settings->scale = fmin((double)(settings->max.x - 2 * settings->border.x) / (fabs(orthogonal_projection((t_int3D){map->max.x, 0, 0}, map, settings->map_base).x) + fabs(orthogonal_projection((t_int3D){0, map->max.y, 0}, map, settings->map_base).x)), (double)(settings->max.y - 2 * settings->border.y) / (fmax(fabs(proj_xymax.y), fabs(proj_abyss.y)) + fmax(fabs(orthogonal_projection((t_int3D){0, 0, 0}, map, settings->map_base).y), fabs(proj_apex.y))));
	settings->obj_center = orthogonal_projection((t_int3D){map->max.x, map->max.y, map->apex.z}, map, settings->map_base);
	make_offset(settings, map);
	return (settings);
}
