/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/25 04:43:41 by gdornic          ###   ########.fr       */
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

//instructions tools
void	ps_swap(int *p1, int *p2);
void	ps_rotate(t_stack *s);
void	ps_rrotate(t_stack *s);
void	ps_push(t_stack *s1, t_stack *s2);

#endif
