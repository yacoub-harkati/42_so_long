CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
LIBFT = ./libft/libft.a
INCLUDE = -I./libft/libft.h -I./minilibx-linux/mlx.h 
MLX_FLAGS = -Lminilibx-linux -L/usr/lib/X11 -lXext -lX11
MLX_LIB = ./minilibx-linux/libmlx_Linux.a

NAME = so_long
RM = rm -f

all: $(NAME)

.SECONDARY: $(OBJS)

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(SRC:.c=.o) $(LIBFT) $(INCLUDE) $(MLX_FLAGS) $(MLX_LIB)

bonus: $(OBJS_BONUS)
	make -C libft
	make -C minilibx-linux 
	$(CC) $(CFLAGS) -o $(NAME)  $(SRC_BONUS:.c=.o) $(LIBFT)  $(INCLUDE) $(MLX_FLAGS) $(MLX_LIB)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

clean:
	make clean -C libft
	make clean -C minilibx-linux
	$(RM) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: clean fclean all re
