NAME = pipex
CC = cc
SRCS = utils.c find_path.c main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g
LIBFT_PATH = ./LIBFTall/
LIBFT_LIB = $(LIBFT_PATH)libft.a
LFLAGS = -LLIBFTall/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LFLAGS) -o pipex $(OBJS) $(LIBFT_LIB)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_PATH) 
	make fclean -C $(LIBFT_PATH)

fclean: clean
	rm -rf pipex

re: fclean all

.PHONY: all clean fclean re LIBFTall