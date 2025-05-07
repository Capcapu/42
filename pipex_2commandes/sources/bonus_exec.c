/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:19:08 by csolari           #+#    #+#             */
/*   Updated: 2025/03/19 14:39:13 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void execute(char *argv, char **env)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = ft_path_cmd(cmd[0], env);
	if (!path)
	{
		ft_putstr_fd("error: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		ft_free_tab(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, env) == -1)
		error("execve");
}
