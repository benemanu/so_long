NAME = so_long.out

CC = cc

INCLUDE = -lXext -lX11

LIBFTNAME = libft.a
LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFTNAME))

MLX_NAME = libmlx_Linux.a
MLX_DIR = minilibx-linux/
MLX = $(addprefix $(MLX_DIR), $(MLX_NAME))

CFLAGS = -Wall -Werror -Wextra -g

SRC = main.c so_long_utils.c check_map.c check_pathing.c get_map.c free_maps.c mlx_own.c mlx_key.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C $(LIBFT_DIR)
	@cc $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(INCLUDE) -o $(NAME)

play: all
#@make -C ./ clean
	@./$(NAME) map_files/test1.ber

val: all
	make -C ./ clean
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--verbose \
	--log-file=valgrind-out.txt \
		./$(NAME) map_files/test1.ber
	
noall:
	norminette -R CheckForbiddenSourceHeader *.h *.c
	norminette -R CheckForbiddenSourceHeader libft/
	
clean:
	rm -f *.o
	@make clean -C $(LIBFT_DIR)

fclean:
	rm -f *.o
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

re: fclean all

.PHONY: all clean fclean re
