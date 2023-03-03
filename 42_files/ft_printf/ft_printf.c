/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:36:09 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/03 19:13:46 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print c, return i + 1
//return -1 if an error occurs
size_t	usual_print(char c, size_t i)
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

//search for an allowed format, print it with the associate argument
//and return the number of characters printed(j) plus i
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
	while (format[j] && ft_isdigit(format[i]))
	{
		field_width[0] = field_width[0] * 10 + format[j] - '0';
		j++;
	}
	while (format[j] && format[j] == '.')
	{
		field_width[1] = 1;
		j++;
	}
	while (format[j] && ft_isdigit(format[i]))
	{
		field_width[2] = field_width[2] * 10 + format[j] - '0';
		j++;
	}
	if (ft_strchr("cspdiuxX%", format[j]))
		return (print_with_format(..));
	else
		return (usual_print());
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
			i = usual_print(format[i], i);
		if (i < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (i);
}
