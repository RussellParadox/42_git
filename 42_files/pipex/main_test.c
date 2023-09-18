/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:52:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/18 16:30:30 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	***new_split;
	char	**split;
	int	*nb;
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_printf("%s\n", envp[i]);
		i++;
	}
	nb = shield(malloc(sizeof(int) * 400), 0);
	split = shield_array(ft_split("lfa djf:flka kfjls:f lksd", ':'), 2, 0);
	new_split = shield(malloc(sizeof(char **) * 4), 2);
	i = 0;
	while (i < 3)
	{
		new_split[i] = shield_array(ft_split(split[i], ' '), 2, 0);
		if (new_split[i] == NULL && !shield(NULL, 2))
			return (1);
		i++;
	}
	new_split[i] = NULL;
	shield_array(new_split, 3, 1);
	shield(NULL, 2);
	while (i-- > 0)
	{
	}
}
