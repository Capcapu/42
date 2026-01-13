/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:28:37 by csolari           #+#    #+#             */
/*   Updated: 2025/03/25 14:34:46 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc(char *limiter)
{
	int		fd[2];
	int		len_lim;
	char	*line;

	len_lim = ft_strlen(limiter);
	if (pipe(fd) == -1)
		error("pipe");
	while (1)
	{
		ft_putstr_fd("heredoc>", 1);
		line = get_next_line(0);
		if (!line | (!ft_strncmp(line, limiter, len_lim)
				&& line[len_lim] == '\n'))
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void	pid_error_close(int *fd, t_fd *file_fd)
{
	close(fd[0]);
	close(fd[1]);
	free(file_fd);
	error("fork");
}

void	pid_close_fd(int *fd, t_fd *file_fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(file_fd->outfd);
	if (file_fd->infd != -1)
		close(file_fd->infd);
}

void	child_process(char *argvi, char **env, t_fd *file_fd, int i)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("pipe");
	pid = fork();
	if (pid == -1)
		pid_error_close(fd, file_fd);
	else if (pid == 0)
	{
		pid_close_fd(fd, file_fd);
		if (!(i == 2 && file_fd->infd == -1))
		{
			free(file_fd);
			execute(argvi, env);
		}
		free(file_fd);
		exit(EXIT_FAILURE);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	last_child_process(char *argvi, char **env, t_fd *file_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(file_fd->outfd);
		free(file_fd);
		error("fork");
	}
	else if (pid == 0)
	{
		dup2(file_fd->outfd, STDOUT_FILENO);
		close(file_fd->outfd);
		if (file_fd->infd != -1)
			close(file_fd->infd);
		free(file_fd);
		execute(argvi, env);
	}
	else
		close(file_fd->outfd);
}
