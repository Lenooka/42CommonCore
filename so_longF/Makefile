NAME = so_long
CC = cc
SRCS = convert_check.c create_map.c error_handle.c exit_destroy.c ft_calloc.c ft_sostrjoin.c ft_sostrlen.c hook_keys.c initial_img.c win_size_count.c init_game.c win_size.c  ft_main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra -g
MLX_FLAGS = -lmlx -lX11 -lXext
LIBFT_PATH = ./LIBFTall/
LIBFT_LIB = $(LIBFT_PATH)libft.a
LFLAGS = -LLIBFTall/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH) --no-print-directory
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LFLAGS) -o so_long $(OBJS) $(LIBFT_LIB)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_PATH) --no-print-directory
	make fclean -C $(LIBFT_PATH) --no-print-directory

fclean: clean
	rm -rf so_long

re: fclean all

.PHONY: all clean fclean re LIBFTall