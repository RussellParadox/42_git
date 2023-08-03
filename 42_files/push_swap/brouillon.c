/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brouillon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:47:15 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/03 15:47:17 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	depth_evaluate(int i, t_stack *a, t_stack *b, int depth)
{
	int	cost;
	int	d;

	cost = evaluate(i, position(a->item[i], b), a, b);
	d = 0;
	while (d < depth)
	{
		place_item_silent(i, position(a->item[i], b), a, b);
		i = choose_item(a, b);
		cost += evaluate(i, position(a->item[i], b), a, b);
		d++;
	}
}
