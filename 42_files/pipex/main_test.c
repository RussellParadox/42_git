/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:52:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/14 17:28:28 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	char	***new_split;
	char	**split;
	int	*nb;
	int	i;

	nb = shield(malloc(sizeof(int) * 1000), 0);
	if (nb == NULL)
		return (1);
	split = shield_array(ft_split("fl dajf:djf al:flsd kafj", ':'), 2, 0);
	if (split == NULL)
		return (1);
	new_split = shield(malloc(sizeof(char **) * 4), 0);
	if (new_split == NULL)
		return (1);
	i = 0;
	while (i < 3)
	{
		new_split[i] = ft_split(split[i], ' ');
		if (!new_split[i] || !shield_array(new_split[i], 2, 0))
			return (1);
		i++;
	}
	new_split[3] = NULL;
	shield(NULL, 0);
	shield(NULL, 0);
}
