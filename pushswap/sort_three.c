/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:33:30 by otolmach          #+#    #+#             */
/*   Updated: 2023/11/19 17:48:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_max(t_list *list)
{
    int max;
    int i;

    max = list->stacks[A][0];
    i = 1;
    while (i < list->size[A])
    {
        if (list->stacks[A][i] > max)
            max = list->stacks[A][i];

        i++;
    }

    return max;
}

void sort_three(t_list *list)
{
    int max;

    max = ft_max(list);
    if (list->size[A] == 3)
    {
        if (list->stacks[A][0] == max)
        {
            rotate(list, A, UP);
            printf("ra\n");
        }
        if (list->stacks[A][1] == max)
        {
            rotate(list, A, DOWN);
            printf("rra\n");
        }
        if (list->stacks[A][0] > list->stacks[A][1])
        {
            swap(list, A);
            printf("sa\n");
        }
    }
}

