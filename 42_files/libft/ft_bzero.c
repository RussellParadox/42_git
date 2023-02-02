/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:50:23 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/02 19:01:09 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	*ft_memset(void *s, int c, size_t n)
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
