/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:54:01 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/24 02:27:39 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_shell_error(char *envp[])
{
	char	*shell;

	shell = ft_strrchr(find_envp("SHELL=", envp) + 6, '/') + 1;
	shell_error(shell, NULL);
}

void	shell_error(char *error, char *suffix)
{
	static char	shell[SHELL_LEN];

	if (shell[0] == '\0' && error != NULL)
		ft_memcpy(shell, error, ft_strlen(error));
	else
		print_error(shell, error, suffix);
}

void	print_error(char *prefix, char *error, char *suffix)
{
	if (prefix != NULL)
	{
		ft_putstr_fd(prefix, 2);
		ft_putstr_fd(": ", 2);
	}
	if (error != NULL)
		ft_putstr_fd(error, 2);
	if (suffix != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(suffix, 2);
	}
	else
		ft_putchar_fd('\n', 2);
}
