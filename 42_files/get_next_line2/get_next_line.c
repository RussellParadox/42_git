/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:54:32 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/20 20:56:42 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
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

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	new_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, s1_len);
	ft_memcpy(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}

static char	**ft_split(char const *s, char c)
{
	size_t	word_qt;
	size_t	*word_size;
	char	**split_str;

	if (s == NULL)
		return (NULL);
	word_qt = ft_wordqt(s, c);
	word_size = ft_wordsize(word_qt, s, c);
	if (word_size == NULL)
		return (NULL);
	split_str = ft_splitstr(word_size, word_qt, s, c);
	if (split_str == NULL)
		return (NULL);
	free(word_size);
	return (split_str);
}

static	char	**file_to_str(int fd)
{
	ssize_t		read_size;
	char		**line;
	char		buffer[BUFFER_SIZE];
	char		*str;
	char		*str_tmp;

	str = ft_strjoin("", "");
	read_size = read(fd, buffer, BUFFER_SIZE);
	while(read_size != 0 && read_size != -1)
	{
		str_tmp = str;
		str = ft_strjoin(str_tmp, buffer);
		free(str_tmp);
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	line = ft_split(str, '\n');
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_file	file;
	char		*line;

	if (file.position == 0)
	{
		file.line = file_to_str(fd);
	}
	line = NULL;
	if (file.line[file.position] != NULL)
	{
		line = ft_strjoin(file.line[file.position], "\n");
		free(file.line[file.position]);
		(file.position)++;
	}
	return (line);
}
