#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() 
{
    char *input;

    while (1) 
	{
        input = readline("Minishell <3 : ");
        if (!input)
            break;
        add_history(input);
        printf("%s\n", input);
        free(input);
    }
	free(input);
    return (0);
}
