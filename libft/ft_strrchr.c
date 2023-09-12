/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:19:22 by otolmach          #+#    #+#             */
/*   Updated: 2023/09/05 17:19:26 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i] != c)
	{
		if (s[i] == c)
		{
			return ((char *)(s + i));
		}
		i--;
	}
	if (c == s[i])
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
