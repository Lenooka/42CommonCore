/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otolmach <otolmach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:28:32 by otolmach          #+#    #+#             */
/*   Updated: 2023/12/06 19:26:17 by otolmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h> 
# define UP 0
# define DOWN 1

typedef struct s_list
{
	long	*stacka;
	long	*stackb;
	int		lena;
	int		lenb;
	char	*joinedstr;
	int		*sorted_list;
	int		max_int;
	int		mini;
	char	**splitstr;
	long	*nbr;
	char	*str;
}	t_list;

void	sa(t_list *list);
void	sb(t_list *list);
void	ss(t_list *list);
void	rra(t_list *list);
void	rrb(t_list *list);
void	rrr(t_list *list);
void	ra(t_list *list);
void	rb(t_list *list);
void	rr(t_list *list);
void	pa(t_list *list);
void	pb(t_list *list);
void	rotate(long *stack, int size, int ord);
void	posofmin(t_list *list, int middlena);
void	shortsort(t_list *list);
int		issorted(t_list *list);
void	sortchoice(t_list *list);
void	findmindex(t_list *list);
void	initializelist(t_list *list, char **argv);
void	freememory(t_list *list);
int		populatestacka(t_list *list, int argc, char **argv);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
char	**ft_free(char **str_tab, int i);
int		error_cyntax(char *str);
int		checkdouble(t_list *list);
void	create_index(t_list *list);
void	free_error(t_list *list);
size_t	ft_strlen(const char *s);
int		is_empty(char **str);
void	insertion_sort(t_list *list);
int		max_bits(t_list *list);
void	radix_sort(t_list *list);
void	get_index(t_list *list);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	printcheckr(t_list *list);
void	printcheck(t_list *list);

#endif
