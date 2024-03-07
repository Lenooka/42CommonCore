/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:28:43 by otolmach          #+#    #+#             */
/*   Updated: 2023/12/05 11:11:47 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->lena)
	{
		list->stacka[list->lena - i] = list->stacka[list->lena - i - 1];
		i++;
	}
	list->stacka[0] = list->stackb[0];
	list->lena++;
	list->lenb--;
	i = 0;
	while (i < list->lenb)
	{
		list->stackb[i] = list->stackb[i + 1];
		i++;
	}
	list->stackb[i] = 0;
	write(1, "pa\n", 3);
}

void	pb(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->lenb)
	{
		list->stackb[list->lenb - i] = list->stackb[list->lenb - i - 1];
		i++;
	}
	list->stackb[0] = list->stacka[0];
	list->lenb += 1;
	list->lena -= 1;
	i = 0;
	while (i < list->lena)
	{
		list->stacka[i] = list->stacka[i + 1];
		i++;
	}
	list->stacka[i] = 0;
	write(1, "pb\n", 3);
}
