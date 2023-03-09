/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:52:35 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/09 10:14:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_data
{
	_Bool	flags[5];
	int	field_width[3];
}	t_data;

int	ft_printf(const char *format, ...);

char	*ft_itoa_base(long n, char *b);
char	*ft_chrtostr(char c);
char	*ft_balloc(size_t nmemb, size_t size);

#endif
