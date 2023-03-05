/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:36:09 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/05 13:40:43 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print at most n characters from str, return i + n
//return -1 if an error occurs
size_t	usual_print(char *str, size_t i, size_t n)
{
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
size_t	ft_atoi_field(char *s, size_t *field_width)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		*field_width = *field_width * 10 + s[i] - '0';
		i++;
	}
	return (i);
}

//print a valid format, return i plus the number of characters read
//return -1 if an error occurs
size_t	print_format(_Bool *flags, size_t *field_width, va_list *ap, size_t i)

//search for an allowed format, print it with the associate argument
//and return the number of characters printed plus i
//return -1 if an error occurs
//
//field_width order
//[0]: minimum
//[1]: '.'
//[2]: maximum
size_t	special_print(const char *format, va_list *ap, size_t i)
{
	_Bool	flags[5];
	size_t	field_width[3];
	size_t	j;

	ft_bzero(flags, 5);
	ft_bzero(field_width, 3);
	j = 0;
	while (format[j] && ft_strchr("-0+ #", format[j]) != NULL)
	{
		flags_manager(flags, format[j]);
		j++;
	}
	j += ft_atoi_field(&format[j], &field_width[0]);
	while (format[j] && format[j] == '.')
	{
		field_width[1] = 1;
		j++;
	}
	j += ft_atoi_field(&format[j], &field_width[2]);
	if (ft_strchr("cspdiuxX%", format[j]))
		return (print_format(flags, field_width, &ap, i));
	else
		return (usual_print(format, i, j);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = special_print(&format[i], &ap, i);
		else
			i = usual_print(&format[i], i, 1);
		if (i < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (i);
}
