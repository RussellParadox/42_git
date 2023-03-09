/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 04:47:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/03/09 04:51:59 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrtostr(char c)
{
	char	*str;

	str = (char *)ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = c;
	return (str);
}
