/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <gdornic@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:07:40 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/15 16:08:03 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_file(int fd)
{
	char	*file;
	char	*line;
	char	*tmp;

	file = ft_strdup("");
	if (file == NULL)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = file;
		file = ft_strjoin(file, line);
		if (file == NULL)
			break ;
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	return (file);
}
