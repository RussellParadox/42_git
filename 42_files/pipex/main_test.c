/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:52:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/16 22:39:11 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	***new_split;
	char	**split;
	int	*nb;
	int	i;

	ft_printf("%s\n", ft_strnstr("/bin/ls", "ls", ft_strlen("/bin/ls")));
	ft_printf("%p\n", (void *)1);
	nb = shield(malloc(sizeof(int) * 1000), 0);
	if (nb == NULL)
		return (1);
	split = shield_array(ft_split("fl dajf:djf al:flsd kafj", ':'), 2, 0);
	if (split == NULL)
		return (1);
	i = 0;
	while (split[i] != NULL)
	{
		ft_printf("%s\n", split[i]);
		i++;
	}
	ft_printf("end\n");
	shield_array(split, 2, 1);
	new_split = shield(malloc(sizeof(char **) * 4), 2);
	if (new_split == NULL)
		return (1);
	i = 0;
	while (i < 3)
	{
		new_split[i] = shield_array(ft_split("fadlj flakfs", ' '), 2, 0);
		if (new_split[i] == NULL && shield(NULL, 2) == NULL)
			return (1);
		i++;
	}
	new_split[3] = NULL;
	shield(NULL, 2);
}
