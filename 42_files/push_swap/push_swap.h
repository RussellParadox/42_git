/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/06/27 20:57:03 by gdornic          ###   ########.fr       */
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
	char	id;
}	t_stack;

//init stack
t_stack	*init_stack_a(int argc, char *argv[]);
t_stack	*init_stack_b(int size);

//instructions tools
void	ps_swap(t_stack *s);
void	ps_rotate(t_stack *s);
void	ps_rrotate(t_stack *s);
void	ps_push(t_stack *s1, t_stack *s2);

//sorting algorithms
void	insert_sort(t_stack *a, t_stack *b);

#endif
