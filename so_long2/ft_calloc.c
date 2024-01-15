/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:15:28 by otolmach          #+#    #+#             */
/*   Updated: 2024/01/07 13:54:54 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	p = malloc(sizeof(char) * (nmemb * size));
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
