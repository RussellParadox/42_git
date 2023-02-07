/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:49:02 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/07 15:11:32 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*scpy;
	char	ctochr;

	ctochr = (char)c;
	scpy = (char *)s;
	while (*scpy)
	{
		if (*scpy == ctochr)
			return (scpy);
		scpy++;
	}
	if (!ctochr)
		return (scpy);
	return (NULL);
}
