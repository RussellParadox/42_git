/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/03 13:47:13 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pon_s;
	int		i;

	pon_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		pon_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
