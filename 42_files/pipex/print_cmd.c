/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:41:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/16 01:46:43 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_cmd(char ***cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i] != NULL)
	{
		j = 0;
		while (cmd[i][j] != NULL)
		{
			ft_printf("%s\n", cmd[i][j]);
			j++;
		}
		i++;
	}
}
