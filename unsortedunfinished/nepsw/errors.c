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
	freeMemory(list);
	write(2, "Error\n", 6);
	exit(1);
}