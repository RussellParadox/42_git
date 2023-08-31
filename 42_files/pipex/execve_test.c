/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:40:48 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/31 22:47:37 by gdornic          ###   ########.fr       */
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
	char	**split;

	i = 0;
	while (i < argc)
		printf("argv %d:%s\n", i++, argv[i]);
	//execve(argv[1], argv + 1, envp);
	split = split_arg("awk -F \')\' \'{print $2}\' infile");
	while (*split != NULL)
	{
		printf("%s\n", *split);
		split++;
	}
}
