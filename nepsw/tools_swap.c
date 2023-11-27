
#include "push_swap.h"

void	sa(t_list *list)
{
	int	swap;

	swap = list->stacka[0];
	list->stacka[0] = list->stacka[1];
	list->stacka[1] = swap;
	write(1, "sa\n", 3);
}

void	sb(t_list *list)
{
	int	swap;

	swap = list->stackb[0];
	list->stackb[0] = list->stackb[1];
	list->stackb[1] = swap;
	write(1, "sb\n", 3);
}

void	ss(t_list *list)
{
	int	swap;

	swap = list->stackb[0];
	list->stackb[0] = list->stackb[1];
	list->stackb[1] = swap;
	swap = list->stacka[0];
	list->stacka[0] = list->stacka[1];
	list->stacka[1] = swap;
	write(1, "ss\n", 3);
}