/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:31:06 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/18 18:53:20 by gdornic          ###   ########.fr       */
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
# include <shield.h>
# define SHELL_LEN 50

//init
void	cmd_free(char ***cmd);
char	***init_cmd(int argc, char *argv[]);

//init end fd
int	init_end_fd(int end_fd[2], int argc, char *argv[]);

//choose io fd
void	choose_io_fd(int io_fd[4], int i, int cmd_qt, int end_fd[2]);

//get file
char	*get_file(int fd);

//print cmd
void	print_cmd(char ***cmd);

//split arg
char	**split_arg(char *arg);

//path
char	**init_path(char *envp[]);
char	*find_cmd_path(char **cmd, char **path);

//here_doc
int	here_doc(int end_fd[2], char *argv[]);

//find envp
char	*find_envp(char *variable, char *envp[]);

//print error
void	init_shell_error(char *envp[]);
void	shell_error(char *error, char *suffix);
void	print_error(char *prefix, char *error, char *suffix);

#endif
