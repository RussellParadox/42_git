/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:26:07 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/23 03:45:12 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*init_mlx(t_settings *settings)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->instance = mlx_init();
	mlx->win = mlx_new_window(mlx->instance, settings->max.x, settings->max.y, "fdf");
	return (mlx);
}

void	make_offset(t_settings *settings)
{
	settings->offset.x = 0.5 * (settings->max.x - settings->scale * settings->obj_center.x);
	settings->offset.y = 0.5 * (settings->max.y - settings->scale * settings->obj_center.y);
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
	settings->phi = (t_double3D){M_PI - acos(1 / sqrt(3)), M_PI - acos(1 / sqrt(3)), M_PI - acos(1 / sqrt(3))}; 
	settings->theta = (t_double3D){5 * M_PI / 6, M_PI / 6, -M_PI / 2};
	settings->color_profile = map->color_profile;
	proj_xymax = isometric_projection((t_int3D){map->max.x, map->max.y, 0}, map, settings->phi, settings->theta);
	proj_apex = isometric_projection((t_int3D){map->apex.x, map->apex.y, map->apex.z}, map, settings->phi, settings->theta);
	proj_abyss = isometric_projection((t_int3D){map->abyss.x, map->abyss.y, map->abyss.z}, map, settings->phi, settings->theta);
	settings->scale = fmin((double)(settings->max.x - 2 * settings->border.x) / (fabs(isometric_projection((t_int3D){map->max.x, 0, 0}, map, settings->phi, settings->theta).x) + fabs(isometric_projection((t_int3D){0, map->max.y, 0}, map, settings->phi, settings->theta).x)), (double)(settings->max.y - 2 * settings->border.y) / (fmax(fabs(proj_xymax.y), fabs(proj_abyss.y)) + fmax(fabs(isometric_projection((t_int3D){0, 0, 0}, map, settings->phi, settings->theta).y), fabs(proj_apex.y))));
	settings->obj_center = isometric_projection((t_int3D){map->max.x, map->max.y, map->apex.z}, map, settings->phi, settings->theta);
	make_offset(settings);
	return (settings);
}
