/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/10 09:47:35 by gdornic          ###   ########.fr       */
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

typedef struct s_sequence
{
	int	*move;
	int	depth;
	int	max_depth;
}	t_sequence;

//init stack
t_stack	*init_stack_a(int argc, char *argv[]);
t_stack	*init_stack_b(int size);

//init sequence
t_sequence	*init_sequence(int size);

//printing_tools
void	ps_print(t_stack *a, t_stack *b);
void	print_sequence(t_sequence *sequence);

//instructions tools low
void	ptr_swap(int *p1, int *p2);
void	ps_swap(t_stack *s);
void	ps_rotate(t_stack *s);
void	ps_rrotate(t_stack *s);
void	ps_push(t_stack *s1, t_stack *s2);

//instructions tools low 2
void	ps_ss(t_stack *a, t_stack *b);
void	ps_rr(t_stack *a, t_stack *b);
void	ps_rrr(t_stack *a, t_stack *b);

//instructions tools high
void	ps_npush(t_stack *s1, t_stack *s2, int n);
void	ps_nrotate(t_stack *s, int n);
void	ps_nrrotate(t_stack *s, int n);
void	insert(t_stack *s1, t_stack *s2, int j);

//insert sort
void	insert_sort(t_stack *a, t_stack *b);

//quick sort
int	*init_solution(t_stack *a);
void	quick_sort_solution(int *solution, int first, int last);

//backtrack
void	backtrack(t_stack *a, t_stack *b, t_sequence *sequence, t_sequence *output);

//backtrack tools
void	make_move(int move, t_stack *a, t_stack *b);
void	unmake_move(int move, t_stack *a, t_stack *b);
void	improve_output(t_sequence *sequence, t_sequence *output);

#endif
