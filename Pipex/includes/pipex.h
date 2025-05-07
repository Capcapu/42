/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:47:31 by csolari           #+#    #+#             */
/*   Updated: 2025/03/25 11:49:26 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/includes/libft.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_fd
{
	int	infd;
	int	outfd;
}				t_fd;

char	*ft_path_cmd(char *cmd, char **env);
void	ft_free_tab(char **tab);
void	error(char	*str);
void	execute(char *argv, char **env);
int		ft_open_files(char *argv, int i);
void	last_child_process(char *argvi, char **env, t_fd *file_fd);
void	child_process(char *argvi, char **env, t_fd *file_fd, int i);
void	heredoc(char *limiter);

#endif
