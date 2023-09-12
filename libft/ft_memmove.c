/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:08:35 by otolmach          #+#    #+#             */
/*   Updated: 2023/09/05 13:08:37 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*sc;
	size_t				i;

	dst = (unsigned char *)dest;
	sc = (const unsigned char *)src;
	i = 0;
	if (dst > sc)
	{
		while (n > 0)
		{
			n--;
			dst[n] = sc[n];
		}
	}
	else
	{
		while (i < n)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	return (dest);
}
