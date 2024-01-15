/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:06:04 by olena             #+#    #+#             */
/*   Updated: 2024/01/15 14:38:17 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**envp_path_dir(char **envp)
{
	int		indx;
	char	**result;

	indx = 0;
	while (!ft_strnstr(envp[indx], "PATH", 4))
	{
		indx++;
	}
	result = ft_split(envp[indx] + 5, ':');
	return (result);
}

char    *find_path(char **envp, char *cmd)
{
	int		idx;
	char	*path;
	char	**path_array;

	idx = 0;
	path_array = envp_path_dir(envp);
	while (path_array[idx])
	{
		path = ft_sostrjoin(path_array[idx], "/");
		path = ft_sostrjoin(path, cmd);
		if (!access(path, F_OK))
		{
			free_strings(path_array);
			return (path);
		}
		free(path);
		idx++;
	}
	free_strings(path_array);
	return (0);
}