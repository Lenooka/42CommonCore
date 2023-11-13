#include "push_swap.h"

/*initialize the t_list structure and allocate memory for stacks*/
void initializeList(t_list *list, int argc) 
{
    list->size[A] = 0;
    list->size[B] = 0;
    list->stacks[A] = (int *)malloc(sizeof(int) * argc);
    list->stacks[B] = (int *)malloc(sizeof(int) * argc);
}

void freeMemory(t_list *list)
{
    free(list->stacks[A]);
    free(list->stacks[B]);
}
int convertm(t_list *list, char **argv)
{
    int i;

    i = 0;
    while (argv[i] != NULL)
    {
        list->stacks[A][i] = ft_atoi(argv[i]);
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
        argv = (ft_split(split_argv[1], 32));
        i = 0;
        if (split_argv)
           i = convertm(list, argv);
    }
    else
    {
        i = 0;
        while (i < argc - 1)
        {
            list->stacks[A][i] = ft_atoi(argv[i + 1]);
            i++;
        }
    }
    list->size[A] = i;
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int iferror;
    t_list list;

    initializeList(&list, argc);
    if (list.stacks[A] == NULL || list.stacks[B] == NULL)
        return (1);
    iferror = populateStackA(&list, argc, argv);
    freeMemory(&list);
    return (iferror);
}
