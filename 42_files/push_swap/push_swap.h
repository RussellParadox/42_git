/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:13 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 15:04:03 by gdornic          ###   ########.fr       */
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
	int		*item;
	int		size;
	int		min;
	int		max;
	char	id;
}	t_stack;

typedef struct s_sequence
{
	int	*move;
	int	depth;
	int	max_depth;
	int	rotation_max;
}	t_sequence;

//exit
void	exit_free(t_stack *a, t_stack *b);
int		error_exit(t_stack *a, t_stack *b);

//init stack
t_stack	*init_stack_a(int argc, char **argv);
t_stack	*init_stack_b(int size);

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
void	ps_nswap(t_stack *s, int n);
void	ps_nss(t_stack *s1, t_stack *s2, int n);

//instructions tools high 2
void	ps_nrr(t_stack *s1, t_stack *s2, int n);
void	ps_nrrr(t_stack *s1, t_stack *s2, int n);

//insert sort
void	insert(t_stack *s1, t_stack *s2, int j);
void	insert_sort(t_stack *a, t_stack *b);

//backtrack sort
void	backtrack_sort(t_stack *a, t_stack *b);

//backtrack
void	backtrack(t_stack *a, t_stack *b, t_sequence *sequence, \
		t_sequence *output);

//backtrack tools
void	make_move(int move, t_stack *a, t_stack *b);
void	unmake_move(int move, t_stack *a, t_stack *b);
void	improve_output(t_sequence *sequence, t_sequence *output);
int		symmetric_move(int m1, int m2);

//checker tools
char	*init_instructions(void);
void	apply_instruction(char inst[4], t_stack *a, t_stack *b);

//exchange sort
void	exchange_sort(t_stack *a, t_stack *b);

//selection sort
void	selection_sort(t_stack *a, t_stack *b);

//statistic tools
int		stack_min(t_stack *s);
int		stack_max(t_stack *s);
int		stack_median(t_stack *s, int first, int last);
int		is_sorted(int *array, int size);
int		is_rsorted(int *array, int size);

//gsort 3
void	gsort_3(t_stack *a, t_stack *b);

//gsort 3 tools
int		locate_max(t_stack *s);
int		position(int n, t_stack *s);
int		actualise_joined_index(int i1, int i2, int cost, int size);
int		evaluate_join_cost(int i, int j, t_stack *a, t_stack *b);

//quick sort array
void	quick_sort_array(int *array, int first, int last);

//rotate sort
int		is_rotate_sorted(t_stack *a);
void	rotate_sort(t_stack *a);

//extremum
int		int_min(int x1, int x2);
int		int_dist(int x1, int x2);

//instructions tools high silent
void	ps_snpush(t_stack *s1, t_stack *s2, int n);
void	ps_snrotate(t_stack *s, int n);
void	ps_snrrotate(t_stack *s, int n);
void	ps_snswap(t_stack *s, int n);
void	ps_snss(t_stack *s1, t_stack *s2, int n);

//instructions tools high silent 2
void	ps_snrr(t_stack *s1, t_stack *s2, int n);
void	ps_snrrr(t_stack *s1, t_stack *s2, int n);

#endif
