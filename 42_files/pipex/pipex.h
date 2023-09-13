/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:31:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/13 17:42:32 by gdornic          ###   ########.fr       */
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

//split arg
char	**split_arg(char *arg);

//path
void	path_free(char **path);
char	**init_path(char *envp[]);
char	**find_cmd_path(char **cmd, char **path);

//sec alloc
void	*shield(void *content, int mode);

//sec alloc array
//void	*shield_array(void *root, size_t size, unsigned int depth_max, int mode);

//free array
void	free_array(void *root, size_t size, unsigned int dimension);

#endif
