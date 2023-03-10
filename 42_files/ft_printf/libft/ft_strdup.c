/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:51:38 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/10 15:17:23 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*scpy;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	scpy = (char *)malloc(slen + 1);
	if (scpy == NULL)
		return (NULL);
	ft_memcpy(scpy, s, slen + 1);
	return (scpy);
}
