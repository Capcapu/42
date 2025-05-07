/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:42:29 by csolari           #+#    #+#             */
/*   Updated: 2025/03/14 11:27:27 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_check_files(char **argv)
{
	if (access(argv[1], R_OK) == -1)
		return (ft_putstr_fd("error : pb infile", 2), EXIT_FAILURE);
	if (access(argv[4], F_OK) == -1)
	{
		if (open(argv[4], O_CREAT, 0644) == -1)
			perror("outfile");
	}
	if (access(argv[4], R_OK | W_OK) == -1)
		return (ft_putstr_fd("error : pb outfile", 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	*ft_path_cmd(char *cmd, t_pipex *pipex)
{
	int		i;
	char	*temp1;
	char	*temp2;

	i = 0;
	while (pipex->paths[i])
	{
		temp1 = ft_strjoin(pipex->paths[i], "/");
		temp2 = ft_strjoin(temp1, cmd);
		free(temp1);
		if (access(temp2, X_OK) == 0)
			return (temp2);
		i++;
		free(temp2);
	}
	return (NULL);
}

int	ft_check_cmd(char **argv, t_pipex *pipex)
{
	pipex->in_f_rights = access(argv[1], R_OK);
	pipex->out_f_rights = access(argv[4], R_OK | W_OK);
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->path1 = ft_path_cmd(pipex->cmd1[0], pipex);
	pipex->path2 = ft_path_cmd(pipex->cmd2[0], pipex);
	return (EXIT_SUCCESS);
}

int	ft_check_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc != 5)
		return (ft_putstr_fd("error : incompatible number of arguments", 2),
			EXIT_FAILURE);
	else
	{
		while (argc-- > 0)
		{
			if (ft_strlen(argv[argc]) == 0)
				return (ft_putstr_fd("error : empty argument", 2),
					EXIT_FAILURE);
		}
		if (ft_check_files(argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (ft_check_cmd(argv, pipex) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

// ft_putstr_fd("file ok\n", 1)
// pipex->path1 = NULL; pour n commandes liste chainee ?