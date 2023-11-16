/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:58:38 by otolmach          #+#    #+#             */
/*   Updated: 2023/11/16 18:26:06 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define UP 0
# define DOWN 1
# define A 0
# define B 1

typedef struct s_list
{
	int	*stacks[2];
	int	size[2];

} t_list;

void 	sort_three(t_list *list);
void	swap(t_list *list, int stack);
void	rotate(t_list *list, int stack, int ord);
void	push(t_list *list, int from);
int		notsort(t_list *list, int stack);
void	initializeList(t_list *list, char **argv);
void	freeMemory(t_list *list);
int		populateStackA(t_list *list, int argc, char **argv);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);

# endif
