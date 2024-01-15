/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:39:25 by olena             #+#    #+#             */
/*   Updated: 2024/01/15 18:10:57 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_and_close(int fd, int *pipefd, int child_num)
{
	if (child_num == 1)
	{
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
	}
	else if (child_num == 2)
	{
		dup2(fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
}

void	first_child(int *fd, int *pipefd, char **argv, char **envp)
{
	pid_t	pid;
	char 	*path;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		error_handle("First child creation error!");
	if (pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			error_handle("First child open error!");
		cmd = ft_split(argv[2], ' ');
		path = find_path(envp, cmd[0]);
		if (cmd[0] != NULL && path)
		{
			redirect_and_close(fd[0], pipefd, 1);
			execve(path, cmd, envp);
		}
		else
		{
			free(path);
			error_free_handle(cmd, fd[0], pipefd);
		}
	}
}

void	second_child_crt(int *fd, int *pipefd, char **argv, char **envp)
{
	pid_t	pid;
	char 	*path;
	char	**cmd;

	pid = fork();
	if (pid < 0)
		error_handle("Second child creation error!");
	if (pid == 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] < 0)
			error_handle("Second child open error!");
		cmd = ft_split(argv[3], ' ');
		path = find_path(envp, cmd[0]);
		if (cmd[0] != NULL && path)
		{
			redirect_and_close(fd[1], pipefd, 2);
			execve(path, cmd, envp);
		}
		else
		{
			free(path);
			error_free_handle(cmd, fd[1], pipefd);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2]; /* to store file descriptors for input and output files*/
	int	pipefd[2]; /*manage the file descriptors of a pipe.*/
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
