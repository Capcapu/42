/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:22:22 by csolari           #+#    #+#             */
/*   Updated: 2025/03/19 14:36:23 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_paths_env(char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	return(ft_split(env[i] + 5, ':'));
}

char	*ft_path_cmd(char *cmd, char **env)
{
	int		i;
	char	*temp1;
	char	*temp2;
	char	**paths;

	paths = ft_get_paths_env(env);
	i = 0;
	while (paths[i])
	{
		temp1 = ft_strjoin(paths[i], "/");
		temp2 = ft_strjoin(temp1, cmd);
		free(temp1);
		if (access(temp2, X_OK) == 0)
			return (temp2);
		i++;
		free(temp2);
	}
	return (NULL);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}




int	ft_check_args(int argc, char **argv)
{
	if (argc < 5)
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
	}
	return (EXIT_SUCCESS);
}


// pipex->in_f_rights = access(argv[1], R_OK);
// pipex->out_f_rights = access(argv[4], R_OK | W_OK);

// pipex->path1 = ft_path_cmd(pipex->cmd1[0], pipex);
// pipex->path2 = ft_path_cmd(pipex->cmd2[0], pipex);