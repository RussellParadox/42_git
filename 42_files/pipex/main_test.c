/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:52:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/13 17:54:16 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	char	**split;
	int	*nb;

	nb = shield(malloc(sizeof(int) * 1000), 0);
	if (nb == NULL)
		return (1);
	split = shield_array(ft_split("fldajf:djfal:flsdkafj", ':'), sizeof(char *), 2, 0);
	if (split == NULL)
		return (1);
	shield(NULL, 0);
}
