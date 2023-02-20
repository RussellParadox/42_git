/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:54:53 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/20 21:33:35 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (!size || !nmemb)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb || (nmemb * size) / nmemb != size)
		return (NULL);
	res = malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, nmemb * size);
	return (res);
}

size_t	ft_wordqt(char const *s, char c)
{
	size_t	word_qt;
	char	*pon_s;

	word_qt = 0;
	pon_s = (char *)s;
	while (*pon_s)
	{
		while (*pon_s == c)
		{
			word_qt++;
			pon_s++;
		}
		if (*pon_s != c && (*pon_s || !c))
		{
			word_qt++;
			while (*pon_s != c && *pon_s)
				pon_s++;
			pon_s++;
		}
	}
	return (word_qt);
}

size_t	*ft_wordsize(size_t word_qt, char const *s, char c)
{
	size_t	*word_size;
	size_t	size;
	char	*pon_s;

	pon_s = (char *)s;
	word_size = ft_calloc(word_qt, sizeof(size_t));
	if (word_size == NULL)
		return (NULL);
	while (*pon_s)
	{
		while (*pon_s == c)
		{
			word_size++;
			pon_s++;
		}
		if (*pon_s != c && (*pon_s || !c))
		{
			size = 0;
			while (*pon_s != c && *pon_s)
			{
				size++;
				pon_s++;
			}
			*word_size = size + 1;
		}
	}
	return (word_size - word_qt);
}

char	**ft_splitstr(size_t *word_size, size_t word_qt, \
		char const *s, char c)
{
	char	**split_str;
	int	i;
	int	j;

	split_str = (char **)ft_calloc(word_qt + 1, sizeof(char *));
	i = 0;
	while (i < word_qt)
	{
		j = 0;
		split_str[i] = (char *)ft_calloc(word_size[i] + 1, sizeof(char));
		while (*s != c)
		{
			split_str[i][j] = *s;
			s++;
			j++;
		}
		s++;
		i++;
	}
	split_str[i] = NULL;
	return (split_str);
}
