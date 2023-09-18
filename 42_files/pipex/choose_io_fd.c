/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_io_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdornic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:33:00 by gdornic           #+#    #+#             */
/*   Updated: 2023/09/18 18:39:14 by gdornic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_choice(int io_fd[4], int end_fd[2], int pipe_fd[2])
{
	io_fd[0] = end_fd[0];
	if (pipe(pipe_fd) == -1)
		perror("pipe");
	io_fd[1] = pipe_fd[1];
	io_fd[2] = -1;
	io_fd[3] = pipe_fd[0];
}

void	mid_choice(int io_fd[4], int pipe_fd[2])
{
	io_fd[0] = pipe_fd[0];
	io_fd[2] = pipe_fd[1];
	if (pipe(pipe_fd) == -1)
		perror("pipe");
	io_fd[1] = pipe_fd[1];
	io_fd[3] = pipe_fd[0];
}

void	end_choice(int io_fd[4], int end_fd[2], int pipe_fd[2])
{
	io_fd[0] = pipe_fd[0];
	io_fd[1] = end_fd[1];
	io_fd[2] = pipe_fd[1];
	io_fd[3] = -1;
}

void	choose_io_fd(int io_fd[4], int i, int cmd_qt, int end_fd[2])
{
	static int	pipe_fd[2];

	if (i == 0)
		first_choice(io_fd, end_fd, pipe_fd);
	else if (i == cmd_qt - 1)
		end_choice(io_fd, end_fd, pipe_fd);
	else
		mid_choice(io_fd, pipe_fd);
}
