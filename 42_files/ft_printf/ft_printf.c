/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:36:09 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/09 11:02:56 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print at most n characters from str, return i + n
//return -1 if an error occurs
int	usual_print(const char *str, int i, int n)
{
	ssize_t	state;

	if (str == NULL)
		return (-1);
	state = write(1, str, n);
	if (state < 0)
		return (-1);
	return (i + n);
}

//manage flags
//return 1 if a non-allowed character is detected
//
//flags order
//[0]: '-'
//[1]: '0'
//[2]: '+'
//[3]: ' '
//[4]: '#'
void	flags_manager(_Bool *flags, char c)
{
	if (c == '-')
		flags[0] = 1;
	else if (c == '0')
		flags[1] = 1;
	else if (c == '+')
		flags[2] = 1;
	else if (c == ' ')
		flags[3] = 1;
	else if (c == '#')
		flags[4] = 1;
}

//get data in field_width and return the number of characters read
int	ft_atoi_field(const char *s, int *field_width)
{
	int	i;

	i = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		*field_width = *field_width * 10 + s[i] - '0';
		i++;
	}
	return (i);
}

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
		return (ft_itoa_base((unsigned int)(va_arg(ap, int)), "0123456789abcdef"));
	else if (id == 'X')
		return (ft_itoa_base((unsigned int)(va_arg(ap, int)), "0123456789ABCDEF"));
	else if (id == 'd' || id == 'i')
		return (ft_itoa_base(va_arg(ap, int), "0123456789"));
	else if (id == 'u')
		return (ft_itoa_base(va_arg(ap, unsigned int), "0123456789"));
	else if (id == 'p')
		return (ft_itoa_base((long)va_arg(ap, void *), "0123456789abcdef"));
	return (NULL);
}

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_lower_bound(int bound, int n)
{
	if (n < bound)
		return (bound);
	return (n);
}

char	*prefix_add(char *prefix, char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(prefix, str);
	free(tmp);
	return (str);
}

//deal with the justification, return the concatenation of str_arg and void_str in the good order
//return NULL if an error occurs
char	*justification_dealer(char *str_arg, char *void_str, _Bool left_justify)
{
	char	*str;

	if (left_justify)
		str = ft_strjoin(str_arg, void_str);
	else
		str = ft_strjoin(void_str, str_arg);
	free(void_str);
	return (str);
}

//deal with the flags and the fields width, return a formated string
//return NULL if an error occurs
char	*data_dealer(_Bool *flags, int *field_width, char *str_arg, char id)
{
	char	*void_str;
	size_t	void_len;
	size_t	arg_len;

	if (flags[2] && ft_strchr("diu", id) && !ft_strchr("-", str_arg[0]))
		str_arg = prefix_add("+", str_arg);
	else if (flags[3] && ft_strchr("diu", id) && !ft_strchr("-", str_arg[0]))
		str_arg = prefix_add(" ", str_arg);
	if (id == 'p' || (flags[4] && id == 'x'))
		str_arg = prefix_add("0x", str_arg);
	if (flags[4] && id == 'X')
		str_arg = prefix_add("0X", str_arg);
	if (str_arg == NULL)
		return (NULL);
	arg_len = ft_strlen(str_arg);
	if (id == 's' && field_width[1])
		arg_len = ft_min(field_width[2], arg_len);
	void_len = ft_lower_bound(0, field_width[0] - arg_len);
	void_str = ft_balloc(void_len, sizeof(char));
	if (void_str == NULL)
		return (NULL);
	if (flags[1] && !(flags[0] && ft_strchr("pdiuxX", id)))
		ft_memset(void_str, '0', void_len);
	return (justification_dealer(str_arg, void_str, flags[0]));
}

//print a valid format, return i plus the number of characters printed
//return -1 if an error occurs
int	print_format(t_data *format_data, char id, va_list ap, int i)
{
	int		chr_printed;
	char	*str_arg;
	char	*tmp;
	size_t	str_len;

	str_arg = id_manager(ap, id);
	if (str_arg == NULL)
		return (-1);
	if (str_arg[0] != '%')
	{
		tmp = str_arg;
		str_arg = data_dealer(format_data->flags, format_data->field_width, str_arg, id);
		free(tmp);
		if (str_arg == NULL)
			return (-1);
	}
	str_len = ft_strlen(str_arg);
	chr_printed = usual_print(str_arg, i, str_len);
	free(str_arg);
	return (chr_printed);
}

//search for an allowed format, print it with the associate argument
//and return the number of characters printed plus i
//return -1 if an error occurs
//
//field_width order
//[0]: minimum
//[1]: '.'
//[2]: maximum
int	special_print(const char *format, va_list ap, int i)
{
	t_data	format_data;
	int	j;

	ft_bzero(format_data.flags, 5);
	ft_bzero(format_data.field_width, 3);
	j = 0;
	while (format[j] && ft_strchr("-0+ #", format[j]) != NULL)
	{
		flags_manager(format_data.flags, format[j]);
		j++;
	}
	j += ft_atoi_field(&format[j], &(format_data.field_width[0]));
	while (format[j] && format[j] == '.')
	{
		format_data.field_width[1] = 1;
		j++;
	}
	j += ft_atoi_field(&format[j], &(format_data.field_width[2]));
	j++;
	if (ft_strchr("cspdiuxX%", format[j]))
		return (print_format(&format_data, format[j], ap, i));
	else
		return (usual_print(format, i, j));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = special_print(&format[i], ap, i);
		else
			i = usual_print(&format[i], i, 1);
		if (i < 0)
			return (-1);
	}
	va_end(ap);
	return (i);
}
