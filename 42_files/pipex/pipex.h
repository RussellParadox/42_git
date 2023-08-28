/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:31:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/08/28 16:31:37 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <libft.h>
# include <libftprintf.h>
# include <get_next_line.h>

//init
void	cmd_free(char ***cmd);
char	***init_cmd(int argc, char *argv[], char *envp[]);

//get file
char	*get_file(int fd);

//print cmd
void	print_cmd(char ***cmd);

#endif
