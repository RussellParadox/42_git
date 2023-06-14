/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/14 20:04:58 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SORTING_ALGO
# include <libft.h>
# include <get_next_line.h>
# include <libftprintf.h>
# include <limits.h>

typedef struct s_stack
{
	int	*item;
	int	size;
}	t_stack;

//init stack
int	*init_stack_a(int argc, char *argv[]);

//instructions
void	ps_swap(int *stack);

#endif
