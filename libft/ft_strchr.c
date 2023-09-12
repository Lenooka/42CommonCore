/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:07:39 by otolmach          #+#    #+#             */
/*   Updated: 2023/09/05 17:07:41 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*i;

	i = (char *)s;
	while (*i != '\0')
	{
		if (*i == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}
