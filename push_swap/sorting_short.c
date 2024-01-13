/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:28:40 by otolmach          #+#    #+#             */
/*   Updated: 2023/12/06 19:07:10 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortchoice(t_list *list)
{
	if (list->lena < 10)
		shortsort(list);
	else
		radix_sort(list);
}

void	findmindex(t_list *list)
{
	int	i;

	i = 0;
	list->mini = 0;
	while (i < list->lena)
	{
		if (list->stacka[list->mini] > list->stacka[i])
			list->mini = i;
		i++;
	}
}

int	issorted(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < list->lena)
	{
		while (j < list->lena)
		{
			if (list->stacka[i] > list->stacka[j] && i < j)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	shortsort(t_list *list)
{
	int	middlen;

	while (list->lena != 1 && issorted(list))
	{
		middlen = list->lena / 2;
		findmindex(list);
		if (list->mini == 0)
			pb(list);
		else if (list->mini == 1)
		{
			if (list->stacka[0] > list->stacka[list->lena - 1])
				ra(list);
			else
				sa(list);
		}
		else
		{
			if (list->stacka[0] > list->stacka[1])
				sa(list);
			posofmin(list, middlen);
		}
	}
	while (list->lenb > 0)
		pa(list);
}

void	posofmin(t_list *list, int middlena)
{
	if (list->mini < middlena)
	{
		ra(list);
	}
	else if (list->mini >= middlena)
	{
		rra(list);
	}
}
