/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:28:37 by otolmach          #+#    #+#             */
/*   Updated: 2023/12/04 13:15:21 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort_stack_b(t_list *list, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && issorted(list))
	{
		if (((list->stackb[0] >> j) & 1) == 0)
			rb(list);
		else
			pa(list);
	}
	if (!issorted(list))
	{
		while (list->lenb != 0)
			pa(list);
	}
}

void	radix_sort(t_list *list)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = list->lena;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = list->lena;
		while (size-- && issorted(list))
		{
			if (((list->stacka[0] >> j) & 1) == 0)
				pb(list);
			else
				ra(list);
		}
		radix_sort_stack_b(list, list->lenb, bit_size, j + 1);
	}
	while (list->lenb != 0)
		pa(list);
}
