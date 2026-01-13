/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:47:31 by csolari           #+#    #+#             */
/*   Updated: 2025/03/19 14:22:14 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/includes/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		in_f_rights;
	int		out_f_rights;
	int		heredoc;
	char	**cmd1;
	char	**cmd2;
	char	**paths;
	char	*path1;
	char	*path2;
	int		pipefd[2];
	int		infd;
	int		outfd;
	char	*error;
}					t_pipex;

typedef struct s_fd
{
	int	infd;
	int	outfd;
}				t_fd;

int		ft_check_args(int argc, char **argv);
t_pipex	*ft_init_struct(char **env);
void	free_t_pipex(t_pipex *pipex);
char	*ft_path_cmd(char *cmd, char **env);
void	ft_free_tab(char **tab);
char	**ft_get_paths_env( char **env);
void	error(char	*str);
void	heredoc(int argc, char *limiter);
void	execute(char *argv, char **env);
void	ft_wait(int argc, char **argv);
void	child_process(char *argv, char **env);
void	last_child_process(char *argv, char **env, int outfd);
void execute(char *argv, char **env);
#endif
