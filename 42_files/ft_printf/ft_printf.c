/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:36:09 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/10 12:04:43 by gdornic          ###   ########.fr       */
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
		str_arg = data_dealer(format_data->flags, \
			format_data->field_width, str_arg, id);
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
	int		j;

	ft_memset(format_data.flags, 0, 5);
	ft_memset_int(format_data.field_width, 0, 3);
	j = 1;
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
	if (ft_strchr("cspdiuxX%", format[j]))
		return (print_format(&format_data, format[j], ap, i));
	else
		return (usual_print(format, i, j));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		chr_printed;

	va_start(ap, format);
	i = 0;
	chr_printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			chr_printed = special_print(&format[i], ap, i);
			i++;
			while (!ft_strchr("cspdiuxX%", format[i]))
				i++;
		}
		else
			chr_printed = usual_print(&format[i], i, 1);
		if (chr_printed < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (chr_printed);
}
