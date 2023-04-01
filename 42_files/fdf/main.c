/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:21:24 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/02 01:19:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map;
	size_t	i;
	size_t	j;

	map = get_the_map(argc, argv);
	i = 0;
	while (i < map->ymax + 1)
	{
		j = 0;
		while (j < map->xmax + 1)
		{
			ft_printf("%d ", (map->height)[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
