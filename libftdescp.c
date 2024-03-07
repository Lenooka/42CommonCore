int		ft_atoi(const char *str); // Converts a string to an integer
void	ft_bzero(void *s, size_t n); //Writes zeroes to a block of memory
void	*ft_calloc(size_t nmemb, size_t size); //Allocates memory for an array and initializes it to zero.
int		ft_isalnum(int c); //Checks if a character is alphanumeric (a letter or digit).
int		ft_isalpha(int c); //: Checks if a character is a letter.
int		ft_isascii(int c); //Checks if a character is an ASCII character (0-127).
int		ft_isdigit(int c); //Checks if a character is a digit (0-9).
int		ft_isprint(int c); //Checks if a character is a printable character.
char	*ft_itoa(int n); //Converts an integer to a string.
void	*ft_memchr(const void *s, int c, size_t n); //Searches for a character in a block of memory.
int		ft_memcmp(const void *s1, const void *s2, size_t n); //Compares two blocks of memory.
void	*ft_memcpy(void *dest, const void *src, size_t n); //Copies a block of memory from one location to another.
void	*ft_memmove(void *dest, const void *src, size_t n); //copies a block of memory, even if the src and dest overlap.
void	*ft_memset(void *s, int c, size_t n); //: Sets a block of memory to a specified value.
void	ft_putchar_fd(char c, int fd); // Writes a character to a file descriptor.
void	ft_putendl_fd(char *s, int fd); //Writes a string followed by a newline to a file descriptor.
void	ft_putnbr_fd(int n, int fd); //Writes an integer to a file descriptor.
void	ft_putstr_fd(char *s, int fd); //Writes a string to a file descriptor.
char	**ft_split(char const *s, char c); //Splits a string into an array of substrings based on a delimiter.
char	*ft_strchr(const char *s, int c); //Locates the first occurrence of a character in a string.
char	*ft_strdup(const char *s); //Duplicates a string.
char	*ft_strjoin(char const *s1, char const *s2); //: Concatenates two strings into a new string.
void	ft_striteri(char *s, void (*f)(unsigned int, char*)); //Applies a function to each character in a string with its index.
size_t	ft_strlcat(char *dst, const char *src, size_t size); //Concatenates two strings with size control.
size_t	ft_strlcpy(char *dst, const char *src, size_t size); //Safely copies a string to a buffer of a specified size.
size_t	ft_strlen(const char *s); // Computes the length of a string.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); //Applies a functn to each char in a str with its ind and creates a new str.
int		ft_strncmp(const char *s1, const char *s2, size_t n); //Compares two strings up to a specified length.
char	*ft_strnstr(const char *big, const char *little, size_t len); // Locates a substring within a string with a specified length.
char	*ft_strrchr(const char *s, int c); //Locates the last occurrence of a character in a string
char	*ft_strtrim(char const *s1, char const *set); //Removes specified leading and trailing characters from a string.
char	*ft_substr(char const *s, unsigned int start, size_t len); //Extracts a substring from a string.
int		ft_tolower(int c); // Converts an uppercase letter to lowercase.
int		ft_toupper(int c); //Converts a lowercase letter to uppercase.
