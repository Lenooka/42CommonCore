NAME = push_swap
SRCS = errors.c ft_atol.c utils.c ft_split.c ft_strlen.c tools_push.c tools_rotate.c tools_rrotate.c tools_swap.c sorting_short.c radix.c  pusw_main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o push_swap $(OBJS) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf push_swap

re: fclean all

.PHONY: all clean fclean re
