/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:55:05 by gdornic           #+#    #+#             */
/*   Updated: 2023/02/21 13:33:36 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# include <unistd.h>
# include <stdlib.h>

typedef struct s_file
{
	char	**line;
	size_t	position;
}	t_file;

char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_wordqt(char const *s, char c);
size_t	*ft_wordsize(size_t word_qt, char const *s, char c);
char	**ft_splitstr(size_t *word_size, size_t word_qt, \
		char const *s, char c);

#endif
