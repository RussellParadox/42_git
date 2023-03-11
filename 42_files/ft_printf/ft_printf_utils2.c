/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:45:11 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/12 00:15:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//get the next argument, transform and return it into a string
char	*id_manager(va_list ap, char id)
{
	if (id == '%')
		return (ft_strdup("%"));
	else if (id == 'c')
		return (ft_chrtostr((char)va_arg(ap, int)));
	else if (id == 's')
		return (ft_strdup(va_arg(ap, char *)));
	else if (id == 'x')
		return (ft_itoa_base((unsigned int)(va_arg(ap, int)), \
			"0123456789abcdef"));
	else if (id == 'X')
		return (ft_itoa_base((unsigned int)(va_arg(ap, int)), \
			"0123456789ABCDEF"));
	else if (id == 'd' || id == 'i')
		return (ft_itoa_base(va_arg(ap, int), "0123456789"));
	else if (id == 'u')
		return (ft_itoa_base(va_arg(ap, unsigned int), "0123456789"));
	else if (id == 'p')
		return (ft_itoa_base_pointer((unsigned long long) \
			va_arg(ap, void *), "0123456789abcdef"));
	return (NULL);
}

//deal with the justification, return the concatenation of str_arg(max len is
//arg_len) and void_str in the good order
//return NULL if an error occurs
char	*justification_dealer(char *str_arg, char *void_str, \
	size_t arg_len, char left_justify)
{
	char	*str;
	char	*tmp;
	//size_t	str_len;

	//str_len = ft_min(ft_strlen(str_arg), arg_len);
	str = ft_substr(str_arg, 0, arg_len);
	free(str_arg);
	if (str == NULL)
		return (NULL);
	tmp = str;
	if (left_justify && arg_len == 1)
		str = inclusive_strjoin(str, void_str);
	else if (left_justify)
		str = ft_strjoin(str, void_str);
	else
		str = ft_strjoin(void_str, str);
	free(void_str);
	free(tmp);
	return (str);
}

//manage argument's flags, return the managed argument
char	*argflags_manager(char *str_arg, char *flags, char id)
{
	if (str_arg == NULL)
		return (ft_strdup("(null)"));
	else if (flags[2] && ft_strchr("diu", id) && !ft_strchr("-", str_arg[0]))
		return (prefix_add("+", str_arg, id));
	else if (flags[3] && ft_strchr("diu", id) && !ft_strchr("-", str_arg[0]))
		return (prefix_add(" ", str_arg, id));
	else if (id == 'p' || (flags[4] && id == 'x'))
		return (prefix_add("0x", str_arg, id));
	else if (flags[4] && id == 'X')
		return (prefix_add("0X", str_arg, id));
	else
		return (ft_strdup(str_arg));
}

//deal with the flags and the fields width, return a formated string
//return NULL if an error occurs
char	*data_dealer(char *flags, int *field_width, char *str_arg, char id)
{
	char	*void_str;
	size_t	void_len;
	size_t	arg_len;

	str_arg = argflags_manager(str_arg, flags, id);
	if (str_arg == NULL)
		return (NULL);
	if (id == 'c')
		arg_len = 1;
	else
		arg_len = ft_strlen(str_arg);
	if (id == 's' && ft_strncmp(str_arg, "(null)", sizeof(str_arg)) \
	&& field_width[1])
		arg_len = ft_min(field_width[2], arg_len);
	void_len = ft_lower_bound(0, field_width[0] - arg_len);
	void_str = ft_balloc(void_len + 1, sizeof(char));
	if (void_str == NULL)
		return (NULL);
	if (flags[1] && !(flags[0] && ft_strchr("pdiuxX", id)))
		ft_memset(void_str, '0', void_len);
	return (justification_dealer(str_arg, void_str, arg_len, flags[0]));
}
