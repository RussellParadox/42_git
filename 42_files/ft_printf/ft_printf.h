/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:52:35 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/09 17:04:20 by gdornic          ###   ########.fr       */
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

int		ft_printf(const char *format, ...);
int	ft_atoi_field(const char *s, int *field_width);

size_t	ft_min(size_t a, size_t b);
size_t	ft_lower_bound(int bound, int n);

char	*ft_itoa_base(long n, char *b);
char	*ft_chrtostr(char c);
char	*ft_balloc(size_t nmemb, size_t size);
char	*id_manager(va_list ap, char id);
char	*justification_dealer(char *str_arg, char *void_str, size_t arg_len, _Bool left_justify);
char	*data_dealer(_Bool *flags, int *field_width, char *str_arg, char id);
char	*prefix_add(char *prefix, char *str);

void	*ft_memset_int(void *s, int c, size_t n);

void	flags_manager(_Bool *flags, char c);

#endif
