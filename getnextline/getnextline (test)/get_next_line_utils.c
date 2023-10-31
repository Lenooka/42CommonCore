/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:06:55 by otolmach          #+#    #+#             */
/*   Updated: 2023/10/14 20:46:59 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *buffer)
{
	char	*js;
	size_t	j;
	size_t	i;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !buffer)
		return (NULL);
	j = 0;
	i = -1;
	js = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(buffer)) + 1));
	if (js == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			js[i] = s1[i];
	while (buffer[j] != '\0')
		js[i++] = buffer[j++];
	js[ft_strlen(s1) + ft_strlen(buffer)] = '\0';
	free(s1);
	s1 = NULL;
	return (js);
}

char	*ft_subline(char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!s1[i])
		return (NULL);
	while (s1[i] && s1[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		result[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_sub_new_line(char *s1)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		s1 = (NULL);
		return (NULL);
	}
	i++;
	while (s1[i])
		s1[j++] = s1[i++];
	s1[j] = '\0';
	return (s1);
}
