#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "LIBFTall/libft.h"

int	check_syntax(char *in)
{
	int i = 0;
	while (in[i])
	{
		if (in[i] == (char)'"')
			return 1;
		i++;
	}
	return 0;

}

int main() 
{
    char *input;

    while (1) 
	{
        input = readline("Minishell <3 : ");
        if (input == NULL)
            break;
        add_history(input);
        if (check_syntax(input) == 1)
        {
            printf("Invalid syntax\n");
            continue ;
        }
		if (ft_strlen(input) == 0)
        	printf("%s", input);
		else
		 	printf("%slalal\n", input);
        free(input);
    }
	free(input);
    return (0);
}
