/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:08:58 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/11 00:08:42 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_belongto(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			sub_len;
	char			*trim_str;
	char			*iterator;
	unsigned int	start;
	unsigned int	end;

	iterator = (char *)s1;
	sub_len = ft_strlen(s1);
	start = 0;
	while (ft_belongto(set, *iterator))
	{
		start++;
		iterator++;
	}
	while (*(iterator + 1))
		iterator++;
	end = 0;
	while (ft_belongto(set, *iterator))
	{
		end++;
		iterator--;
	}
	sub_len -= (start + end);
	trim_str = ft_substr(s1, start, sub_len);
	return (trim_str);
}
