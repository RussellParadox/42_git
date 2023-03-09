/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:48:04 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/09 03:14:50 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrsize(long n, size_t radix)
{
	size_t	size;

	size = 0;
	if (n == 0)
		size++;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= radix;
	}
	return (size);
}

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char	*ft_itoa_base(long n, char *b)
{
	char	*ntostr;
	size_t	radix;
	size_t	nsize;
	size_t	i;

	radix = ft_strlen(b);
	nsize = ft_nbrsize(n, radix);
	ntostr = (char *)ft_calloc(nsize + 1, sizeof(char));
	if (ntostr != NULL)
	{
		i = nsize - 1;
		if (n == 0)
			ntostr[0] = '0';
		if (n < 0)
			ntostr[0] = '-';
		while (n != 0)
		{
			ntostr[i] = b[ft_abs(n % radix)];
			n /= radix;
			i--;
		}
	}
	return (ntostr);
}
