/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:32:10 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/16 17:45:46 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_spaces_f(int *fd, int *pipefd, char **argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv[2], ' ');
	path = find_path(envp, cmd[0]);
	if (cmd[0] != NULL && path)
	{
		redirect_and_close(fd[0], pipefd, 1, cmd);
		if (execve(path, cmd, envp) == -1)
			error_free_handle(cmd, fd[0], pipefd, "execve in child 2 fail");
	}
	else
	{
		free(path);
		command_not_found(cmd, fd[1], pipefd, argv[2]);
	}
}

void	handle_path_f(int *fd, int *pipefd, char **argv, char **envp)
{
	char	*path;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(argv[2], '/');
	while (cmd[i] != NULL)
		i++;
	path = find_path(envp, cmd[i - 1]);
	if (cmd[i - 1] != NULL && path)
	{
		redirect_and_close(fd[0], pipefd, 1, cmd);
		if (execve(path, &cmd[i - 1], envp) == -1)
			error_free_handle(cmd, fd[0], pipefd, "execve in child 2 fail");
	}
	else
	{
		free(path);
		command_not_found(cmd, fd[0], pipefd, argv[2]);
	}
}

void	path_spaces_s(int *fd, int *pipefd, char **argv, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv[3], ' ');
	printf("%s\n", cmd[0]);
	path = find_path(envp, cmd[0]);
	if (cmd[0] != NULL && path)
	{
		redirect_and_close(fd[1], pipefd, 2, cmd);
		if (execve(path, cmd, envp) == -1)
			error_free_handle(cmd, fd[1], pipefd, "execve in child 2 fail");
	}
	else
	{
		free(path);
		command_not_found(cmd, fd[1], pipefd, argv[3]);
	}
}

void	handle_path_s(int *fd, int *pipefd, char **argv, char **envp)
{
	char	*path;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(argv[3], '/');
	while (cmd[i] != NULL)
		i++;
	path = find_path(envp, cmd[i - 1]);
	if (cmd[i - 1] != NULL && path)
	{
		redirect_and_close(fd[1], pipefd, 2, cmd);
		if (execve(path, &cmd[i - 1], envp) == -1)
			error_free_handle(cmd, fd[1], pipefd, "execve in child 2 fail");
	}
	else
	{
		free(path);
		command_not_found(cmd, fd[1], pipefd, argv[3]);
	}
}
