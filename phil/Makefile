NAME = philo
SRCS = ft_main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o philo $(OBJS) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf philo

re: fclean all

.PHONY: all clean fclean re