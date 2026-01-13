/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:19:08 by csolari           #+#    #+#             */
/*   Updated: 2025/03/25 14:26:28 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *argv, char **env)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	if (!argv[0] || (argv[0] == ' ' && !argv[1]))
	{
		ft_putstr_fd("error : empty argument\n", 2);
		exit(EXIT_FAILURE);
	}
	cmd = ft_split(argv, ' ');
	path = ft_path_cmd(cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("error: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		ft_free_tab(cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, env) == -1)
		error("execve");
}

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	ft_open_files(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(argv, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("error : no such file or rights : ", 2);
		ft_putendl_fd(argv, 2);
	}
	return (fd);
}
