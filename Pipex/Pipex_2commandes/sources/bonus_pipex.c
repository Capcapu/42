/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:03:14 by csolari           #+#    #+#             */
/*   Updated: 2025/03/20 11:39:50 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_open_files(char *argv, int i)
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
		error("open file");
	return (fd);
}
void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);	
}


void	heredoc(int argc, char *limiter)
{
	int		fd[2];
	int		len_lim;
	char	*line;

	len_lim = ft_strlen(limiter);
	if (argc < 6)
	{
		ft_putstr_fd("error: insufficient number of arguments : heredoc\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error("pipe");
	while (1)
	{
		ft_putstr_fd("heredoc>", 1);
		line = get_next_line(0);
		if (!line | (!ft_strncmp(line, limiter, len_lim) && line[len_lim] == '\n') )
		{
			free(line);
			break;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void child_process(char *argvi, char **env)
{
	pid_t	pid;
	int		fd[2];

	if(pipe(fd) == -1)
		error("pipe");
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		error("fork");
	}
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute(argvi, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void last_child_process(char *argvi, char **env, int outfd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(outfd);
		error("fork");
	}
	else if (pid == 0)
	{
		dup2(outfd, STDOUT_FILENO);
		close(outfd);
		execute(argvi, env);
	}
	else
		close(outfd);
}

void	ft_wait(int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		argc--;
	while(argc - 3 > 0)
	{
		waitpid(-1, NULL, 0);
		argc--;
	}
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	int 	infd;
	int		outfd;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			heredoc(argc, argv[2]);
			outfd = ft_open_files(argv[argc - 1], 0);
		}
		else
		{
			i = 2;
			outfd = ft_open_files(argv[argc - 1], 1);
			infd = ft_open_files(argv[1], 2);
			dup2(infd, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], env);
		last_child_process(argv[argc - 2], env, outfd);
		close(infd);
		ft_wait(argc, argv);
		return (0);
	}
	else
		return (ft_putstr_fd("error : invalid number of arguments\n", 2), 1);
}

// dup2(outfd, STDOUT_FILENO);


// pid_t	pid1;
// pid_t	pid2;
// if (pipe(pipex->pipefd))
// return (EXIT_FAILURE);
// pid1 = first_child(pipex, env);
// if (pid1 == -1)
// return (EXIT_FAILURE);
// pid2 = second_child(pipex, env);
// if (pid2 == -1)
// return (EXIT_FAILURE);
// close(pipex->pipefd[0]);
// close(pipex->pipefd[1]);
// close(pipex->infd);
// close(pipex->outfd);


// int	first_child(t_pipex *pipex, char **env)
// {
// 	pid_t	pid1;

// 	pid1 = fork();
// 	if (pid1 == -1)
// 	{
// 		close(pipex->pipefd[0]);
// 		close(pipex->pipefd[1]);
// 		perror("fork");
// 		free_t_pipex(pipex);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid1 == 0)
// 	{
// 		dup2(pipex->infd, STDIN_FILENO);
// 		dup2(pipex->pipefd[1], STDOUT_FILENO);
// 		close(pipex->pipefd[0]);
// 		execve(pipex->path1, pipex->cmd1, env);
// 	}
// 	return (pid1);
// }



// int	ft_child_fork_exec(char **env, t_pipex **pipex, int number)
// {
// 	int	pid;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		close(pipex->pipefd[0]);
// 		close(pipex->pipefd[1]);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid == 0)
// 	{
// 		dup2(pipex->infd, STDIN_FILENO);
// 		dup2(pipex->pipefd[1], STDOUT_FILENO);
// 		close(pipex->pipefd[0]);
// 		execve(pipex->path1, pipex->cmd1, env);
// 	}
// }