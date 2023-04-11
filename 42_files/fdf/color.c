/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:21:46 by gdornic           #+#    #+#             */
/*   Updated: 2023/04/05 00:25:23 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	to_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	to_t(int trgb)
{
	return (trgb >> 24 & 0xFF);
}

int	to_r(int trgb)
{
	return (trgb >> 16 & 0xFF);
}

int	to_g(int trgb)
{
	return (trgb >> 8 & 0xFF);
}

int	to_b(int trgb)
{
	return (trgb & 0xFF);
}
