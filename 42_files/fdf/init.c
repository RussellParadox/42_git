/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:26:07 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/19 21:53:59 by gdornic          ###   ########.fr       */
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

void	make_offset(t_map *map, t_settings *settings)
{
	settings->offset.x = 0.5 * (settings->max.x - settings->scale * settings->obj_center.x);
	settings->offset.y = 0.5 * (settings->max.y - settings->scale * settings->obj_center.y);
}

t_settings	*settings_init(t_double2D max, double thickness, t_map *map)
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
	settings->thickness = thickness;
	settings->color_profile = map->color_profile;
	proj_xymax = isometric_projection((t_int3D){map->max.x, map->max.y, 0}, map);
	proj_apex = isometric_projection((t_int3D){map->apex.x, map->apex.y, map->apex.z}, map);
	proj_abyss = isometric_projection((t_int3D){map->abyss.x, map->abyss.y, map->abyss.z}, map);
	settings->scale = fmin((double)(settings->max.x - 2 * settings->border.x) / (abs(isometric_projection((t_int3D){map->max.x, 0, 0}, map).x) + abs(isometric_projection((t_int3D){0, map->max.y, 0}, map).x)), (double)(settings->max.y - 2 * settings->border.y) / (fmax(abs(proj_xymax.y), abs(proj_abyss.y)) + fmax(abs(isometric_projection((t_int3D){0, 0, 0}, map).y), abs(proj_apex.y))));
	settings->obj_center = isometric_projection((t_int3D){map->max.x, map->max.y, map->apex.z}, map);
	make_offset(map, settings);
	return (settings);
}
