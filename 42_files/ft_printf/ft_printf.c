/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:36:09 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/09 02:48:59 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print at most n characters from str, return i + n
//return -1 if an error occurs
int	usual_print(char *str, int i, int n)
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
int	ft_atoi_field(char *s, int *field_width)
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

//get the next argument, transform and return it into a list
char	*id_manager(va_list *ap, char id)
{
	if (id == '%')
		return (ft_strdup("%"));
	if (id == 'c')
		return (ft_strdup(&va_arg(ap, char)));
	else if (id == 's')
		return (ft_strdup(va_arg(ap, char *)));
	else if (id == 'p' || id == 'x' || id == 'X')
		return (ft_itoa_base(va_arg(ap, int)), "0123456789abcdef");
	else if (id == 'd' || id == 'i')
		return (ft_itoa_base(va_arg(ap, int), "0123456789"));
	else if (id == 'u')
		return (ft_itoa_base(va_arg(ap, unsigned int), "0123456789"));
}

//print a valid format, return i plus the number of characters printed
//return -1 if an error occurs
int	print_format(t_data *format_data, char id, va_list *ap, int i)
{
	char	*str_arg;
	size_t	str_size;
	void	*arg;

	arg = NULL;
	str_arg = id_manager(ap, id);
	return (usual_print(str_arg, i, str_size));
}

//search for an allowed format, print it with the associate argument
//and return the number of characters printed plus i
//return -1 if an error occurs
//
//field_width order
//[0]: minimum
//[1]: '.'
//[2]: maximum
int	special_print(const char *format, va_list *ap, int i)
{
	t_data	format_data;
	int	j;

	ft_bzero(format_data->flags, 5);
	ft_bzero(format_data->field_width, 3);
	j = 0;
	while (format[j] && ft_strchr("-0+ #", format[j]) != NULL)
	{
		flags_manager(format_data->flags, format[j]);
		j++;
	}
	j += ft_atoi_field(&format[j], format_data->field_width[0]);
	while (format[j] && format[j] == '.')
	{
		format_data->field_width[1] = 1;
		j++;
	}
	j += ft_atoi_field(&format[j], format_data->field_width[2]);
	if (ft_strchr("cspdiuxX%", format[j]))
		return (print_format(&format_data, &ap, i));
	else
		return (usual_print(format, i, j);
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
