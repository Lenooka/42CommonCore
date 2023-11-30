#include "push_swap.h"

void	sortchoice(t_list *list)
{
	if (list->lena < 10)
		shortsort(list);
	/*else
		radix_sort(list);*/
}


void	findmindex(t_list *list)
{
	int	i;

	i = 0;
	list->min_i = 0;
	while (i < list->lena)
	{
		if (list->stacka[list->min_i] > list->stacka[i])
			list->min_i = i;
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
            {
				return (1);
            }
			j++;
		}
		j = 0;
		i++;
	}
    write(1, "sort\n", 5);
	return (0);
}

void	shortsort(t_list *list)
{
	int	middlen;

	while (list->lena != 1 && issorted(list))
	{
		middlen = list->lena / 2;
		findmindex(list);
		if (list->min_i == 0)
			pb(list);
		else if (list->min_i == 1)
		{
			if (list->stacka[0] > list->stacka[list->lena - 1])
				ra(list);
			else
				sa(list);
		}
		else
		{
			middlena(list, middlen);
		}
	}
}

void	middlena(t_list *list, int middlena)
{
	if (list->stacka[0] > list->stacka[1])
		sa(list);
	if (list->min_i < middlena)
		ra(list);
	else if (list->min_i >= middlena)
		rra(list);
}