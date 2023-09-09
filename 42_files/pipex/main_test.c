/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:52:08 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/09 18:18:06 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int	*array;
	char	*str;
	char	*join;

	array = (int *)sec_alloc(malloc(sizeof(int) * 3), 0);
	if (array == NULL)
		return (1);
	str = (char *)sec_alloc(malloc(sizeof(char) * 5), 0);
	if (str == NULL)
		return (1);
	ft_strlcpy(str, "AH!!", 5);
	ft_printf("%s\n", str);
	join = (char *)sec_alloc(ft_strjoin(str, "coucou"), 0);
	sec_alloc(str, 1);
	ft_printf("%s\n", join);
	sec_alloc(NULL, 1);
}
