/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:22:22 by csolari           #+#    #+#             */
/*   Updated: 2025/03/21 16:22:20 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_get_paths_env(char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	return (ft_split(env[i] + 5, ':'));
}

char	*ft_path_cmd(char *cmd, char **env)
{
	int		i;
	char	*temp1;
	char	*temp2;
	char	**paths;

	if (!cmd || !cmd[0])
		return (NULL);
	paths = ft_get_paths_env(env);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		temp1 = ft_strjoin(paths[i], "/");
		temp2 = ft_strjoin(temp1, cmd);
		free(temp1);
		if (access(temp2, X_OK) == 0)
		{
			ft_free_tab(paths);
			return (temp2);
		}
		i++;
		free(temp2);
	}
	return (ft_free_tab(paths), NULL);
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
