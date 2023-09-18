/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:00:35 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/18 16:07:01 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_envp(char *variable, char *envp[])
{
	while (*envp != NULL && ft_strncmp(variable, *envp, ft_strlen(variable)))
		envp++;
	return (*envp);
}
