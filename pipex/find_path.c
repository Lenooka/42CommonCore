/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 03:06:04 by olena             #+#    #+#             */
/*   Updated: 2024/01/15 03:38:04 by olena            ###   ########.fr       */
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

char    *find_path(char *cmd, char **envp)
{
	int		idx;
	char	*path;
	char	**path_array;

	idx = 0;
	path_array = envp_path_dir(envp);
	while (path_array[i])
	{
		path = ft_sostrjoin(paths[i], "/");
		path = ft_sostrjoin(path, cmd);
		if (!access(path, F_OK))
		{
			free_strings(path_array);
			return (path);
		}
		free(path);
		i++;
	}
	free_strings(path_array);
	return (0);
}