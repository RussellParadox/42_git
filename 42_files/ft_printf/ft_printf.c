/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:36:09 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/02 18:12:55 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print c, return i + 1
//return -1 if an error occurs
size_t	usual_print(char c, size_t i)
{
}

//search for an allowed format, print it with the associate argument and return the number of characters printed plus i
//return -1 if an error occurs
size_t	special_print(const char *format, va_list *ap, size_t i)
{
	_Bool	flags[6];

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
