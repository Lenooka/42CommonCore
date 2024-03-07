/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:39:25 by olena             #+#    #+#             */
/*   Updated: 2024/01/16 17:46:57 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_and_close(int fd, int *pipefd, int child_num, char **c)
{
	if (child_num == 1)
	{
		if (dup2(fd, 0) == -1)
			error_free_handle(c, fd, pipefd, "Dup2 of file fd in child 1 fail");
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			error_free_handle(c, fd, pipefd, "Dup2 of pipefd in child 1 fail");
	}
	else if (child_num == 2)
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
			error_free_handle(c, fd, pipefd, "Dup2 of file fd in child 2 fail");
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			error_free_handle(c, fd, pipefd, "Dup2 of pipefd in child 2 fail");
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
}

void	first_child(int *fd, int *pipefd, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_handle("First child creation error!");
	if (pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			error_handle(argv[1]);
		if (ft_strchr(argv[2], '/') != NULL)
			handle_path_f(fd, pipefd, argv, envp);
		else
			path_spaces_f(fd, pipefd, argv, envp);
	}
}

void	second_child_crt(int *fd, int *pipefd, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_handle("Second child creation error!");
	if (pid == 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			error_handle(argv[4]);
		if (ft_strchr(argv[3], '/') != NULL)
			handle_path_s(fd, pipefd, argv, envp);
		else
		{
			path_spaces_s(fd, pipefd, argv, envp);
		}
	}
}
/* to store file descriptors for input and output files
manage the file descriptors of a pipe.*/

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pipefd[2];

	if (argc != 5)
		error_handle("Wrong amount of arguments");
	if (!envp || envp[0][0] == '\0')
		error_handle("Environment pointer error");
	if (pipe(pipefd) == -1)
		error_handle("Pipe fd error");
	first_child(fd, pipefd, argv, envp);
	second_child_crt(fd, pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}
