/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 05:32:51 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/22 05:33:24 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//free allocated memory at ptr only if ptr isn't set to NULL
void	no_null_free(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

//free the stacks and their content at the end of the program
void	exit_free(t_stack *a, t_stack *b)
{
	if (a != NULL)
		no_null_free(a->item);
	no_null_free(a);
	if (b != NULL)
		no_null_free(b->item);
	no_null_free(b);
}

int	error_exit(t_stack *a, t_stack *b)
{
	exit_free(a, b);
	ft_printf("Error\n");
	return (1);
}
