/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:21:24 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/23 23:53:27 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map;
	char	*dot;

	if (argc == 2)
	{
		dot = ft_strchr(argv[1], '.');
		if (dot != NULL)
			dot = ft_strchr(dot + 1, '.');
		if (dot == NULL \
		&& ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) != NULL)
		{
			map = get_the_map(argc, argv);
			if (map == NULL)
				return (0);
			print_map(map);
			free_map(map);
		}
		else
			ft_printf("Wrong file format\n");
	}
	else
		ft_printf("Wrong amount of argument(s)\n");
	return (0);
}
