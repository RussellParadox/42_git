/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:43:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/05 20:38:42 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	free_size;

	src_len = ft_strlen(src);
	dst_len = ft_min(size, ft_strlen(dst));
	free_size = size - dst_len;
	if (src_len > free_size)
	{
		ft_memcpy(dst + dst_len, src, free_size);
	}
	else
	{
		ft_memcpy(dst + dst_len, src, src_len);
	}
	return (src_len + dst_len);
}
