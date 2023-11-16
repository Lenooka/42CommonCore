#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}
int	main(int argc, char **argv)
{
	int	i = 0;
	int	start = 0;
	int	end = 0;
	int	f = 0;
	char	*first;

	while(argv[1][i] == ' ')
	{
		i++;
	}
	start = i;
	while(argv[1][i] != ' ')
		i++;
	end = i;
	first = (char *)malloc(sizeof(char) * (end - start));
	first = ft_strncpy(first, &argv[1][start], end - start);
	while(argv[1][i] == ' ')
	{
		i++;
	}
	while(argv[1][i] != '\0')
	{
		if (argv[1][i] != ' ')
			write(1, &argv[1][i], 1);
		if (argv[1][i] == ' ' && argv[1][i + 1] != ' ' || argv[1][i + 1] == '\0')
			write(1, " ", 1);
		i++;
	}
	while(first[f] != '\0')
	{
		write(1, &first[f], 1);
		f++;
	}
	free(first);
	write(1, "\n", 1);
	return (0);

}