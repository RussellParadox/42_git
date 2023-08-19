/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:40:48 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/19 14:48:39 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	arr_test(int array[2])
{
	array[0] = 2;
}

int	main(int argc, char *argv[], char *envp[])
{
	int	array[2];

	array[0] = 0;
	array[1] = 0;
	arr_test(array);
	printf("a[0]: %d\n", array[0]);
}
