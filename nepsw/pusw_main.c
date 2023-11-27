#include "push_swap.h"

void initializeList(t_list *list, char **argv) 
{
    int ac;

    ac = 0;
    list->lena = 0;
    list->lenb = 0;
    while (argv[ac] != NULL)
        ac++;
    list->stacka = (long *)malloc(sizeof(int) * ac);
    list->stackb = (long *)malloc(sizeof(int) * ac);
}

void freeMemory(t_list *list)
{
    free(list->stacka);
    free(list->stackb);
    free(list);
}
int convertm(t_list *list, char **argv)
{
    int     i;
    long    n;

    i = 0;
    while (argv[i] != NULL)
    {

        if (error_cyntax(argv[i]))
            free_error(list);
        list->stacka[i] = ft_atol(argv[i]);
        n = list->stacka[i];
        if (n > INT_MAX || n < INT_MIN)
            free_error(list); /*free and eror printf*/
        i++;
    }
    return (i);
}

int populateStackA(t_list *list, int argc, char **argv)
{
    int i;
    char **split_argv;

    i = 0;
    if (argc == 1 || argc == 2 && !argv[1][0])
        return (1);
    else if (argc == 2)
    {
        split_argv = (ft_split(argv[1], 32));
        i = 0;
        initializeList(list, split_argv);
        i = convertm(list, split_argv);
    }
    else
    {
        initializeList(list, argv);
        i = convertm(list, argv + 1);
    }
    list->lena = i;
    return (0);
}

int main(int argc, char **argv)
{
    int i = 0;
    int iferror;
    t_list *list;

    list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return 1;
    iferror = populateStackA(list, argc, argv);
    if (list->stacka == NULL || list->stackb == NULL)
        return (1);
    /*if (is_empty(argv) || duplicate(list))
		free_error(list);*/
    if (issorted(list))
		sortmechanism(list);
	return (iferror);
}