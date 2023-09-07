/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:40:48 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/07 07:07:58 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "pipex.h"

void	arr_test(int array[2])
{
	array[0] = 2;
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	int	fd[2];
	char	buff;
	char	delete;

	i = 0;
	while (i < argc)
		printf("argv %d:%s\n", i++, argv[i]);
	fd[0] = open(argv[1], O_RDWR | O_TRUNC);
	close(fd[0]);
}
