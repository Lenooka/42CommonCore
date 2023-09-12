/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:30:50 by otolmach          #+#    #+#             */
/*   Updated: 2023/09/06 19:30:52 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	litlen;
	size_t	i;

	i = 0;
	litlen = ft_strlen(little);
	if (litlen == 0)
	{
		return ((char *)big);
	}
	if (len < litlen)
	{
		return (NULL);
	}
	while (i <= len - litlen)
	{
		if (ft_strncmp(big + i, little, litlen) == 0)
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
