/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:18:50 by csolari           #+#    #+#             */
/*   Updated: 2025/03/13 17:26:39 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_get_paths_env(t_pipex *pipex, char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	pipex->paths = ft_split(env[i] + 5, ':');
}

t_pipex	*ft_init_struct(char **env)
{
	t_pipex	*pipex;

	pipex = ft_calloc(sizeof(t_pipex), 1);
	if (!pipex)
		return (NULL);
	pipex->in_f_rights = -1;
	pipex->out_f_rights = -1;
	pipex->heredoc = -1;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->paths = NULL;
	pipex->path1 = NULL;
	pipex->path2 = NULL;
	pipex->error = NULL;
	ft_get_paths_env(pipex, env);
	return (pipex);
}

static void	ft_free_tab(char **tab)
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

void	free_t_pipex(t_pipex *pipex)
{
	ft_free_tab(pipex->cmd1);
	ft_free_tab(pipex->cmd2);
	ft_free_tab(pipex->paths);
	free(pipex->path1);
	free(pipex->path2);
	free(pipex);
}
