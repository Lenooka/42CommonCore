#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define UP 0
# define DOWN 1

typedef struct s_list{
	long	*stacka;
	long	*stackb;
	int		lena;
	int		lenb;
	char	*joinedstr;
	int		*sorted_list;
	int		max_int;//(?)
	int		min_i;
	char	**splitstr;
	long	*nbr;//(?)
}	t_list;

void	sa(t_list *list);
void	sb(t_list *list);
void	ss(t_list *list);
void	rra(t_list *list);
void	rrb(t_list *list);
void	rrr(t_list *data);
void	ra(t_list *list);
void	rb(t_list *list);
void	rr(t_list *list);
void	pa(t_list *list);
void	pb(t_list *list);
void	othercase(t_list *list, int a);
void	myshortsort(t_list *list);
int		issorted(t_list *list);
void	sortmechanism(t_list *list);
void	initializeList(t_list *list, char **argv);
void	freeMemory(t_list *list);
int		populateStackA(t_list *list, int argc, char **argv);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
int	error_cyntax(char *str);
void	free_error(t_list *list);
size_t	ft_strlen(const char *s);
void	findmin(t_list *data);


#endif