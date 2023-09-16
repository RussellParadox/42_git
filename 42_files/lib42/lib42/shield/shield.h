/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:22:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/14 16:43:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIELD_H
# define SHIELD_H
# include <libft.h>
# include <stddef.h>
# include <stdlib.h>

//free array
void	free_array(void *root, unsigned int dimension);

//shield
void	*shield(void *content, int mode);

//shield array
void	*shield_array(void *root, unsigned int dimension, int mode);

#endif
