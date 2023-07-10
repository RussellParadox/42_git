/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:54:10 by gdornic           #+#    #+#             */
/*   Updated: 2023/07/10 14:36:36 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_move_test(int move)
{
	if (move == 1)
		ft_printf("sa ");
	if (move == 2)
		ft_printf("sb ");
	if (move == 3)
		ft_printf("ss ");
	if (move == 4)
		ft_printf("pa ");
	if (move == 5)
		ft_printf("pb ");
	if (move == 6)
		ft_printf("ra ");
	if (move == 7)
		ft_printf("rb ");
	if (move == 8)
		ft_printf("rr ");
	if (move == 9)
		ft_printf("rra ");
	if (move == 10)
		ft_printf("rrb ");
	if (move == 11)
		ft_printf("rrr ");
}

void	print_move(int move)
{
	if (move == 1)
		ft_printf("sa\n");
	if (move == 2)
		ft_printf("sb\n");
	if (move == 3)
		ft_printf("ss\n");
	if (move == 4)
		ft_printf("pa\n");
	if (move == 5)
		ft_printf("pb\n");
	if (move == 6)
		ft_printf("ra\n");
	if (move == 7)
		ft_printf("rb\n");
	if (move == 8)
		ft_printf("rr\n");
	if (move == 9)
		ft_printf("rra\n");
	if (move == 10)
		ft_printf("rrb\n");
	if (move == 11)
		ft_printf("rrr\n");
}

//print stacks for testing tools
void	ps_print(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	ft_printf("_ _\n");
	while (i < a->size || i < b->size)
	{
		if (i < a->size)
			ft_printf("%d", a->item[i]);
		else
			ft_printf(" ");
		ft_printf(" ");
		if (i < b->size)
			ft_printf("%d", b->item[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("_ _\n");
	ft_printf("a b\n");
}

void	print_sequence(t_sequence *sequence)
{
	int	i;
	int	n;

	n = sequence->max_depth;
	i = 0;
	while (i <= n)
	{
		print_move(sequence->move[i]);
		i++;
	}
}
