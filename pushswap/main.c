#include "push_swap.h"

/*initialize the t_list structure and allocate memory for stacks*/
void initializeList(t_list *list, char **argv) 
{
    int ac;

    ac = 0;
    list->size[A] = 0;
    list->size[B] = 0;
    while (argv[ac] != NULL)
        ac++;
    list->stacks[A] = (int *)malloc(sizeof(int) * ac);
    list->stacks[B] = (int *)malloc(sizeof(int) * ac);
}

void freeMemory(t_list *list)
{
    free(list->stacks[A]);
    free(list->stacks[B]);
}
int convertm(t_list *list, char **argv)
{
    int     i;
    long    n;

    i = 0;
    while (argv[i] != NULL)
    {
        /*if (error_syntax(argv[i])) if number and + -
            free_error(&list);*/
        list->stacks[A][i] = ft_atol(argv[i]);
        /*n = list->stacks[A][i];
        if (n > INT_MAX || n < INT_MIN)
            free_error(&list); free and eror printf*/
        i++;
    }
    printf("%d ", list->stacks[A][i - 1]);
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
    list->size[A] = i;
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int iferror;
    t_list *list;

    iferror = populateStackA(list, argc, argv);
    if (list->stacks[A] == NULL || list->stacks[B] == NULL)
        return (1);
    if (!(notsort(list, A)))
    {
        if (list->size[A] == 3)
            sort_three(list);
    } 
    freeMemory(list);
    return (iferror);
}
