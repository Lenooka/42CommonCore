/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sostrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:00:56 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/05 19:43:44 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_sostrjoin(char *s1, char const *s2)
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
