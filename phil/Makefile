NAME = philo
CC = cc
SRCS = ft_main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g
LIBFT_PATH = ./libftall/
LIBFT_LIB = $(LIBFT_PATH)libft.a
LFLAGS = -Llibftall/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(LFLAGS) -o philo $(OBJS) $(LIBFT_LIB)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_PATH) 
	make fclean -C $(LIBFT_PATH)

fclean: clean
	rm -rf philo

re: fclean all

.PHONY: all clean fclean re LIBFTall