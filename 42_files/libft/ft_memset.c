/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:12:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/02 19:00:30 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_toint;

	s_toint = (unsigned char *)s;
	while (n > 0)
	{
		*s_toint++ = (unsigned char)c;
		n -= sizeof(char);
	}
	return (s);
}
