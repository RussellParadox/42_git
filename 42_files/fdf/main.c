/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:21:24 by gdornic           #+#    #+#             */
/*   Updated: 2023/05/20 13:09:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc == 2)
	{
		map = get_the_map(argc, argv);
		if (map == NULL)
			return (0);
		print_map(map);
		free_map(map);
	}
	return (0);
}
