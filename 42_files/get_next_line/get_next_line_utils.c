/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:54:53 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/21 19:24:33 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_first_line(char *buf)
{
	char	first_line[BUFFER_SIZE + 1];
	size_t	i;
	size_t	fl_len;

	ft_memset(first_line, '\0', BUFFER_SIZE + 1);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
			first_line[i] = buf[i];
			i++;
	}
	first_line[i] = buf[i];
	fl_len = 0;
	while (first_line[fl_len])
		fl_len++;
	ft_memset(buf, '\0', fl_len);
	i = 0;
	while (buf[fl_len + i])
	{
		buf[i] = buf[fl_len + i];
		i++;
	}
	ft_memset(buf + i, '\0', fl_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	new_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, s1_len);
	ft_memcpy(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pon_s;
	size_t			i;

	pon_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		pon_s[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pon_dest;
	unsigned char	*pon_src;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	pon_dest = (unsigned char *)dest;
	pon_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pon_dest[i] = pon_src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup_to(char c, char *str, char *buf)
{
	char	*str_dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	str_dup = (char *)malloc((len + 2) * sizeof(char));
	i = 0;
	while (i <= len && str_dup != NULL)
	{
		str_dup[i] = str[i];
		i++;
	}
	str_dup[len + 1] = '\0';
	ft_first_line(buf);
	return (str_dup);
}
