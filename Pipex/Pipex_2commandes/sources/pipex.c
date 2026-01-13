/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csolari <csolari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:43:54 by csolari           #+#    #+#             */
/*   Updated: 2025/03/13 14:54:42 by csolari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_child(t_pipex *pipex, char **env)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
	{
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		perror("fork");
		free_t_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	else if (pid1 == 0)
	{
		dup2(pipex->infd, STDIN_FILENO);
		dup2(pipex->pipefd[1], STDOUT_FILENO);
		close(pipex->pipefd[0]);
		execve(pipex->path1, pipex->cmd1, env);
	}
	return (pid1);
}

int	second_child(t_pipex *pipex, char **env)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
	{
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		perror("fork");
		free_t_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		dup2(pipex->pipefd[0], STDIN_FILENO);
		dup2(pipex->outfd, STDOUT_FILENO);
		close(pipex->pipefd[1]);
		execve(pipex->path2, pipex->cmd2, env);
	}
	return (pid2);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	pid_t	pid1;
	pid_t	pid2;

	pipex = NULL;
	pipex = ft_init_struct(env);
	if (ft_check_args(argc, argv, pipex) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	pipex->infd = open(argv[1], O_RDONLY);
	pipex->outfd = open(argv[4], O_TRUNC | O_WRONLY);
	if (pipe(pipex->pipefd))
		return (EXIT_FAILURE);
	pid1 = first_child(pipex, env);
	if (pid1 == -1)
		return (EXIT_FAILURE);
	pid2 = second_child(pipex, env);
	if (pid2 == -1)
		return (EXIT_FAILURE);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(pipex->infd);
	close(pipex->outfd);
	wait(NULL);
	free_t_pipex(pipex);
	return (EXIT_SUCCESS);
}

// pid_t pid;

// pid = fork();
// if (pid == -1)
// {
// 	perror("fork");
// 	exit(EXIT_FAILURE);
// }
// else if (pid == 0) //un child process for each command
// {
// 	printf("I am the child process \n");
// 	exit(EXIT_SUCCESS);
// }
// else
// {
// 	printf("I am the parent process\n");
// 	wait(NULL); //execute child process avant de continuer dans le parent
// permet d executer les child process avant de continuer dans le parent
// 	printf("child process terminated\n");
// }

// (void)argv;
// (void)argc;
// (void)env;

// printf("path1 %s\n", pipex->path1);
// printf("commande %s\n", pipex->cmd1[0]);
// int fd = open(argv[1], O_RDONLY);
// int fd2 = open(argv[4], O_TRUNC | O_WRONLY);
//un child process for each command

// printf("ceci ne dervait pas s afficher2\n");

// void	print_open_fds(void)
// {
// 	int	fd;

// 	printf("\n🔍 [DEBUG] File descriptors ouverts:\n");
// 	for (fd = 0; fd < 1024; fd++)
// 	{
// 		if (fcntl(fd, F_GETFD) != -1) // Vérifie si le FD est ouvert
// 			printf("  FD %d est ouvert\n", fd);
// 	}
// }

// print_open_fds();
