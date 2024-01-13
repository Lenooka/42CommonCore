#include "push_swap.h"

int	sort(t_list *list, int stack)
{
	int	i;

	i = 0;
	while (i < list->size[stack] - 1)
	{
		if (list->stacks[stack][i] > list->stacks[stack][i + 1])
		{
			//printf("notsorted\n");
			return 0;
		}
		i++;
	}
	printf("sorted\n");
	return (1);
}

// Define a function that sorts stack a in ascending order
void	sort_stack_a(t_list *list)
{
	int min; // The minimum value in stack a
	int pos; // The position of the minimum value in stack a
	int i; // A loop variable

	// Repeat until stack a is sorted
	while (!(notsort(list, A)))
	{
		min = list->stacks[A][0]; // Initialize the minimum value to the top of stack a
		pos = 0; // Initialize the position to 0
		// Loop through stack a to find the minimum value and its position
		for (i = 1; i < list->size[A]; i++)
		{
			if (list->stacks[A][i] < min) // If a smaller value is found
			{
				min = list->stacks[A][i]; // Update the minimum value
				pos = i; // Update the position
			}
		}
		// Rotate stack a until the minimum value is at the top
		while (list->stacks[A][0] != min)
		{
			if (pos <= list->size[A] / 2) // If the position is closer to the top
			{
				rotate(list, A, UP);
                printf("ra\n"); // Rotate stack a up
			}
			else // If the position is closer to the bottom
			{
				rotate(list, A, DOWN);
                printf("rra\n"); // Rotate stack a down
			}
		}
		// Push the minimum value from stack a to stack b
		push(list, A);
        printf("pa\n");
	}
	// Push back all the values from stack b to stack a in ascending order
	while (list->size[B] > 0)
	{
		push(list, B);
        printf("pb\n");
	}
}

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
    free(list);
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
        if (list->size[A] > 3 && 5 <= list->size[A])
        {
            sort_stack_a(list);
        }
        else
        {
            radix_sort(list);
        }
    }
    sort(list, A);
    freeMemory(list);
    return (iferror);
}