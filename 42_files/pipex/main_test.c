/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:52:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/12 19:23:58 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	char	**split;
	char	***new_split;
	int	i;

	split = ft_split("dlf kad:kf ja:fk dasjkf", ':');
	new_split = malloc(sizeof(char **) * 4);
	i = 0;
	while (i < 3)
	{
		new_split[i] = ft_split(split[i], ' ');
		i++;
	}
	new_split[3] = NULL;
	free_array(split, sizeof(char *), 2);
	free_array(new_split, sizeof(char *), 3);
	sec_alloc(NULL, 0);
}
