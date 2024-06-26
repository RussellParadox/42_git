/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/10 12:06:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	*ft_memset_int(void *s, int c, size_t n)
{
	int		*pon_s;
	size_t	i;

	pon_s = (int *)s;
	i = 0;
	while (i < n)
	{
		pon_s[i] = c;
		i++;
	}
	return (s);
}
