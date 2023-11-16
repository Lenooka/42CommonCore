/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:33:30 by otolmach          #+#    #+#             */
/*   Updated: 2023/11/16 18:22:15 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_list *list)
{
	int	i;

	i = 0;
	while (i < 3)
	{ 
		if (list->stacks[A][0] > list->stacks[A][1])
        {
            swap(list, A);
            printf("%s", "sa\n");
        }
        else
        {
            rotate(list, A, UP);
            printf("%s", "ra\n");
        }
		i++;
    }
}