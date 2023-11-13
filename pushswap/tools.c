/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:11:54 by otolmach          #+#    #+#             */
/*   Updated: 2023/11/08 20:14:49 by codespace        ###   ########.fr       */
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

	if (ord == DOWN) /*reverse*/
	{
		i = list->size[stack] - 1;
		temp = list->stacks[stack][list->size[stack] - 1];
		while(i > 0)
		{
			list->stacks[stack][i] = list->stacks[stack][i - 1];
			i--;
		}
		list->stacks[stack][0] = temp;
	}
	else if (ord == UP)
	{
		i = 0;
		temp = list->stacks[stack][0];
		while(i < list->stacks[stack][list->size[stack] - 1])
		{
			list->stacks[stack][i] = list->stacks[stack][i + 1];
			i++;
		}
		list->stacks[stack][list->size[stack] - 1] = temp;
	}
}
void push(t_list *list, int from)
{
    int to;

	to = 1 - from;
    if (list->size[from] > 0) 
	{
		list->size[to]++;
        rotate(list, to, DOWN);
		list->stacks[to][0] = list->stacks[from][0];
        rotate(list, from, UP);
		list->size[from]--;
    }
}

/*
void	print_stacks(t_list *list)
{
	int	i = 0;
	/*swap(list, A);
	printf("%d\t", list->stacks[A][0]);
	swap(list, B);
	printf("%d\n", list->stacks[B][0]);*/
	/*rotate(list, B, DOWN);
	push(list, A);
	while (i < list->size[A])
	{
		printf("%d\n", list->stacks[A][i]);
		i++;
	}
	i = 0;
	while (i < list->size[B])
	{
		printf("\t");
		printf("%d\n", list->stacks[B][i]);
		i++;
	}
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

	list->size[A] = 5;
	list->size[B] = 5;

	list->stacks[A][0] = 1;
	list->stacks[A][1] = 2;
	list->stacks[A][2] = 3;
	list->stacks[A][3] = 4;
	list->stacks[A][4] = 5;
	list->stacks[B][0] = 6;
	list->stacks[B][1] = 7;
	list->stacks[B][2] = 8;
	list->stacks[B][3] = 9;
	list->stacks[B][4] = 0;

	print_stacks(list);

    free(list->stacks[A]);
    free(list->stacks[B]);
    free(list);

    return (0);
}*/


