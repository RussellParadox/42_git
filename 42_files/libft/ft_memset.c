/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/03 00:00:34 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_toint;

	s_toint = (unsigned char *)s;
	while (n > 0)
	{
		*s_toint++ = (unsigned char)c;
		n -= sizeof(unsigned char);
	}
	return (s);
}
