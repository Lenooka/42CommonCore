#include "push_swap.h"

void	rra(t_list *list)
{
	int	temp;
	int	i;

	i = list->lena;
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

	i = list->lenb;
	temp = list->stackb[list->lenb - 1];
	while (i > 0)
	{
		list->stackb[i] = list->stackb[i - 1];
		i--;
	}
	list->stackb[0] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_list *data)
{
	rra(data);
	rrb(data);
	write(1, "rrr\n", 4);
}