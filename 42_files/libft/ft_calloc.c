/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:08:47 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/08 19:30:31 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (!size || !nmemb)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb || (nmemb * size) / nmemb != size)
		return (NULL);
	res = ft_memset(malloc(nmemb * size), 0, nmemb * size);
	if (res == NULL)
		return (NULL);
	return (res);
}
