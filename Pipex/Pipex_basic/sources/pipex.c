/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:03:14 by csolari           #+#    #+#             */
/*   Updated: 2025/03/25 12:17:05 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_fd(int argc, char **argv, t_fd *fd)
{
	int	i;

	fd->infd = -1;
	fd->outfd = -1;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			return (ft_putstr_fd("error: invalid number of arguments\n", 2), 1);
		i = 3;
		heredoc(argv[2]);
		fd->outfd = ft_open_files(argv[argc - 1], 0);
	}
	else
	{
		i = 2;
		fd->outfd = ft_open_files(argv[argc - 1], 1);
		fd->infd = ft_open_files(argv[1], 2);
		dup2(fd->infd, STDIN_FILENO);
	}
	return (i);
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	t_fd	*fd;

	fd = NULL;
	fd = malloc(sizeof(t_fd));
	if (!fd)
		return (ft_putstr_fd("error : malloc failed\n", 2), 1);
	if (argc < 5)
		return (free(fd), ft_putstr_fd("error : too few arguments\n", 2), 1);
	if (!env[0])
		return (free(fd), ft_putstr_fd("error : no environment\n", 2), 1);
	i = open_fd(argc, argv, fd) - 1;
	while (++i < argc - 2)
		child_process(argv[i], env, fd, i);
	if (fd->outfd != -1)
	{
		last_child_process(argv[argc - 2], env, fd);
		close(fd->outfd);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
		close(fd->infd);
	while (wait(NULL) > 0)
		;
	return (free(fd), 0);
}
