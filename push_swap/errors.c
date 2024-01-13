/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:28:10 by otolmach          #+#    #+#             */
/*   Updated: 2023/12/03 14:31:10 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_cyntax(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (((*str < '0' || *str > '9')
				&& *str != ' ' && *str != '-' && *str != '+')
			|| ((*str == '-' || *str == '+') && (*(str + 1) < '0'
					|| *(str + 1) > '9'))
			|| ((*str >= '0' && *str <= '9') && (*(str + 1) == '+'
					|| *(str + 1) == '-')))
			return (1);
		i++;
		str++;
	}
	return (0);
}

void	free_error(t_list *list)
{
	freememory(list);
	write(2, "Error\n", 6);
	exit(1);
}

int	checkdouble(t_list *list)
{
	int	i;
	int	ch;

	i = 0;
	ch = 0;
	while (i < list->lena)
	{
		while (ch < list->lena)
		{
			if (list->stacka[i] == list->stacka[ch] && i != ch)
				return (1);
			ch++;
		}
		ch = 0;
		i++;
	}
	return (0);
}

int	is_empty(char **str)
{
	int	i;
	int	j;
	int	check;

	j = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		check = 1;
		if (!(str[i][j]))
			return (1);
		while (str[i][j])
		{
			if (str[i][j] != ' ')
				check = 0;
			j++;
		}
		if (check == 1)
			return (1);
		i++;
	}
	return (0);
}
