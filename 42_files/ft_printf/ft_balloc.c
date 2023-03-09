/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_balloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:08:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/09 10:14:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_balloc(size_t nmemb, size_t size)
{
	char	*res;

	if (!size || !nmemb)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb || (nmemb * size) / nmemb != size)
		return (NULL);
	res = (char *)malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_memset(res, ' ', nmemb * size);
	res[nmemb * size] = '\0';
	return (res);
}
