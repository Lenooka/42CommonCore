/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:31:18 by olena             #+#    #+#             */
/*   Updated: 2024/01/15 03:37:42 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strings(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	error_handle(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_free_handle(char **cmd, int fd, int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
	free_strings(cmd);
	error_handle("Command not found!")
}