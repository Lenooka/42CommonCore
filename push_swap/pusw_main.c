/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:27:58 by otolmach          #+#    #+#             */
/*   Updated: 2023/12/06 21:38:27 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		iferror;
	t_list	*list;

	if (argc > 1 && (!(is_empty(argv))))
	{
		list = (t_list *)malloc(sizeof(t_list));
		if (list == NULL)
			return (1);
		iferror = populatestacka(list, argc, argv);
		if (list->stacka == NULL || list->stackb == NULL)
			return (1);
		if ((is_empty(argv)) || checkdouble(list))
			free_error(list);
		create_index(list);
		if (issorted(list))
			sortchoice(list);
		freememory(list);
		return (iferror);
	}
	return (0);
}
