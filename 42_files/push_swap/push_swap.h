/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/02 15:35:01 by gdornic          ###   ########.fr       */
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

//instructions tools low
void	ptr_swap(int *p1, int *p2);
void	ps_swap(t_stack *s);
void	ps_rotate(t_stack *s);
void	ps_rrotate(t_stack *s);
void	ps_push(t_stack *s1, t_stack *s2);

//instructions tools high
void	ps_npush(t_stack *s1, t_stack *s2, int n);
void	ps_nrotate(t_stack *s, int n);
void	ps_nrrotate(t_stack *s, int n);
void	insert(t_stack *s1, t_stack *s2, int j);

//insert sort
void	insert_sort(t_stack *a, t_stack *b);

//quick sort
void	array_swap(t_stack *a, t_stack *b, int i1, int i2);
void	quick_sort(t_stack *a, t_stack *b, int first, int last);

#endif
