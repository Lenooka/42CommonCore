#include "push_swap.h"


void radix_sort_stack_b(t_list *list, int b_size, int bit_size, int j)
{
    while (b_size-- && j <= bit_size && !notsort(list, B))
    {
        if (((list->stacks[B][0] >> j) & 1) == 0)
        {
            rotate(list, B, UP);
             printf("rb\n");
        }
        else
        {
            push(list, A);
             printf("pa\n");
        }
    }
    if (notsort(list, B))
        while (list->size[B] != 0)
        {
            push(list, A);
            printf("pa\n");
        }
}

void radix_sort(t_list *list)
{
    int j;
    int bit_size;
    int size;

    bit_size = 0;
    size = list->size[A];
    while (size > 1 && ++bit_size)
        size /= 2;
    j = -1;
    while (++j <= bit_size)
    {
        size = list->size[A];
        while (size-- && !notsort(list, A))
        {
            if (((list->stacks[A][0] >> j) & 1) == 0)
            {
                push(list, B);
                printf("pb\n");
            }
            else
            {
                rotate(list, A, UP);
                printf("ra\n");
            }
        }
        radix_sort_stack_b(list, list->size[B], bit_size, j + 1);
    }
    while (list->size[B] != 0)
        push(list, A);
        {
            printf("pa\n");
        }
}
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
    int i = 0;
    int iferror;
    t_list *list;

    list = (t_list *)malloc(sizeof(t_list)); //to work on windows
	if (list == NULL)
		return 1;
    iferror = populateStackA(list, argc, argv);
    if (list->stacks[A] == NULL || list->stacks[B] == NULL)
        return (1);
    if (!(notsort(list, A)))
    {
        if (list->size[A] == 3)
        {
            sort_three(list);
        }
        else
        {
            radix_sort(list);
        }
    }
    notsort(list, A);
    freeMemory(list);
    return (iferror);
}