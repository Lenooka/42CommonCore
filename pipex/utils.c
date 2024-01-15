/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:31:18 by olena             #+#    #+#             */
/*   Updated: 2024/01/15 14:38:21 by otolmach         ###   ########.fr       */
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
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	error_free_handle(char **cmd, int fd, int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
	if (cmd != NULL)
		free_strings(cmd);
	error_handle("Command not found!");
}

int	ft_sostrlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_sostrjoin(char *s1, char *s2)
{
	char	*c;
	int		i;
	int		i2;

	if (!s2)
		return (NULL);
	i = 0;
	i2 = 0;
	c = (char *)malloc(ft_sostrlen(s1) + ft_sostrlen(s2) + 1);
	if (!c)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
		c[i++] = s2[i2++];
	c[i] = '\0';
	free(s1);
	s1 = NULL;
	return (c);
}
