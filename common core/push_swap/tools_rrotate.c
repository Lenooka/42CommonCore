/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:29:13 by otolmach          #+#    #+#             */
/*   Updated: 2023/12/06 19:18:20 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *list)
{
	int	temp;
	int	i;

	i = list->lena - 1;
	temp = list->stacka[list->lena - 1];
	while (i > 0)
	{
		list->stacka[i] = list->stacka[i - 1];
		i--;
	}
	list->stacka[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_list *list)
{
	int	temp;
	int	i;

	i = list->lenb - 1;
	temp = list->stackb[list->lenb - 1];
	while (i > 0)
	{
		list->stackb[i] = list->stackb[i - 1];
		i--;
	}
	list->stackb[0] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_list *list)
{
	rra(list);
	rrb(list);
	write(1, "rrr\n", 4);
}
