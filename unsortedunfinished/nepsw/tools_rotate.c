
#include "push_swap.h"

void	ra(t_list *list)
{
	int	temp;
	int	i;

	i = 0;
	temp = list->stacka[0];
	while (i <= list->lena)
	{
		list->stacka[i] = list->stacka[i + 1];
		i++;
	}
	list->stacka[list->lena - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_list *list)
{
	int	temp;
	int	i;

	i = 0;
	temp = list->stackb[0];
	while (i <= list->lenb)
	{
		list->stackb[i] = list->stackb[i + 1];
		i++;
	}
	list->stackb[list->lenb - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_list *list)
{
	ra(list);
	rb(list);
	write(1, "rr\n", 3);
}
