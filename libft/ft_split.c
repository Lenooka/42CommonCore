/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:42:53 by otolmach          #+#    #+#             */
/*   Updated: 2023/09/07 15:42:54 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

static int	wrdcnt(char const *s, char c)
{
	unsigned int	i;
	int				cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cont++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (cont);
}

static char	*ft_strncpy(char *dest, const char *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s[i] != '\0') && (i < n))
	{
		dest[i] = s[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*cs;

	cs = (char *)malloc(n + 1);
	if (!cs)
	{
		return (0);
	}
	cs = ft_strncpy(cs, s, n);
	return (cs);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		p;
	int		w;

	i = 0;
	w = 0;
	result = (char **)malloc(sizeof(char *) * (wrdcnt(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		p = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > p)
		{
			result[w] = ft_strndup(s + p, i - p);
			w++;
		}
	}
	result[w] = NULL;
	return (result);
}
