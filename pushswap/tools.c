/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:11:54 by otolmach          #+#    #+#             */
/*   Updated: 2023/11/03 20:13:42 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *list, int stack)
{
	int temp;

	temp = list->stacks[stack][0];
	list->stacks[stack][0] = list->stacks[stack][1];
	list->stacks[stack][1] = temp;
}

void	rotate(t_list *list, int stack, int ord)
{
	int i;
	int	temp;

	i = 1;
	if (ord == UP)
	{
		temp = list->stacks[stack][list->size[stack] - 1];
		while(i < list->size[stack] - 1)
		{
			list->stacks[stack][i - 1] = list->stacks[stack][i];
			i++;
		}
		list->stacks[stack][0] = temp;
	}
	else if (ord == DOWN)
	{
		temp = list->stacks[stack][0];
		while(i > 0)
		{
			list->stacks[stack][i] = list->stacks[stack][i - 1];
			i--;
		}
		list->stacks[stack][0] = temp;
	}
}
void	push(t_list *list, int from)
{
	int	i;
	int to;
	int	temp;

	to = 1 - from;
	temp = list->stacks[from][0];
	list->size[to]++;
	i = list->stacks[to][list->size[to]];
	while (i > 1)
	{
		list->stacks[to][i] = list->stacks[to][i - 1];
		i--;
	}
	list->stacks[to][0] = temp;
}
void	print_stacks(t_list *list)
{
	/*swap(list, A);
	printf("%d\t", list->stacks[A][0]);
	swap(list, B);
	printf("%d\n", list->stacks[B][0]);*/
	rotate(list, A, UP);
	printf("%d\n", list->stacks[A][0]);
	printf("%d\n", list->stacks[A][4]);
}

int main(void)
{
    t_list *list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list == NULL)
        return (1);

	list->stacks[A] = (int*)malloc(sizeof(int) * 10);
	list->stacks[B] = (int*)malloc(sizeof(int) * 10);

	if (list->stacks[A] == NULL || list->stacks[B] == NULL)
	{
        free(list->stacks[A]);
        free(list->stacks[B]);
        free(list);
        return (1);
    }

	list->size[A] = 0;
	list->size[B] = 0;

	list->stacks[A][0] = 1;
	list->stacks[A][1] = 5;
	list->stacks[A][2] = 8;
	list->stacks[A][3] = 0;
	list->stacks[A][4] = 2;
	list->stacks[B][0] = -3;
	list->stacks[B][1] = 9;
	list->stacks[B][2] = 10;
	list->stacks[B][3] = 12;
	list->stacks[B][4] = 4;

	print_stacks(list);

    free(list->stacks[A]);
    free(list->stacks[B]);
    free(list);

    return (0);
}


