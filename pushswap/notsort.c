/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:34:07 by otolmach          #+#    #+#             */
/*   Updated: 2023/11/16 17:40:29 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	notsort(t_list *list, int stack)
{
	int	i;

	i = 0;
	while (i < list->size[stack] - 1)
	{
		if (list->stacks[stack][i] > list->stacks[stack][i + 1])
		{	printf("notsorted\n");
			return 0;
		}
		i++;
	}
	printf("sorted");
	return (1);
}
	