/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:01:42 by otolmach          #+#    #+#             */
/*   Updated: 2023/12/06 21:42:29 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_list *list)
{
	int			i;
	int			j;
	int			k;
	long		*tempa;

	tempa = malloc(list->lena * sizeof * tempa);
	if (!tempa)
		free_error(list);
	i = -1;
	while (++i < list->lena)
	{
		k = 0;
		j = -1;
		while (++j < list->lena)
			if (list->stacka[i] > list->stacka[j])
				k++;
		tempa[i] = k;
	}
	i = list->lena;
	while (i--)
		list->stacka[i] = tempa[i];
	free(tempa);
}

void	initializelist(t_list *list, char **argv)
{
	int	ac;

	ac = 0;
	list->lena = 0;
	list->lenb = 0;
	while (argv[ac])
		ac++;
	list->stacka = (long *)malloc(sizeof(long) * ac);
	if (!list->stacka)
		return ;
	list->stackb = (long *)malloc(sizeof(long) * ac);
	if (!list->stackb)
		return ;
}

void	freememory(t_list *list)
{
	free(list->stacka);
	free(list->stackb);
	free(list);
}

int	convertm(t_list *list, char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (error_cyntax(argv[i]))
			free_error(list);
		list->stacka[i] = ft_atol(argv[i]);
		n = list->stacka[i];
		if (n > INT_MAX || n < INT_MIN)
			free_error(list);
		i++;
	}
	list->lena = i;
	return (i);
}

int	populatestacka(t_list *list, int argc, char **argv)
{
	int		i;
	char	**split_argv;

	i = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_argv = (ft_split(argv[1], 32));
		if (!split_argv)
			return (0);
		i = 0;
		initializelist(list, split_argv);
		i = convertm(list, split_argv);
		ft_free(split_argv, i);
	}
	else
	{
		initializelist(list, argv);
		i = convertm(list, argv + 1);
	}
	list->lena = i;
	return (0);
}
