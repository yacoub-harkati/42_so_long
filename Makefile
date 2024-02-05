CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
INCLUDE = -I./libft -I./minilibx-linux
MLX_FLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT = -Llibft -lft
NAME = so_long
NAME_B = so_long_bonus
RM = rm -f

SRC = \
	actions.c \
	check_2.c \
	check.c \
	flood_fill.c \
	free.c \
	hook.c \
	init.c \
	main.c \
	queue_helpers.c \
	render_2.c \
	render.c \
	utils.c \
	utils_2.c

SRC_BONUS = \
	bonus/actions_bonus.c \
	bonus/check_2_bonus.c \
	bonus/check_bonus.c \
	bonus/flood_fill_bonus.c \
	bonus/free_bonus.c \
	bonus/hook_bonus.c \
	bonus/init_bonus.c \
	bonus/main_bonus.c \
	bonus/queue_helpers_bonus.c \
	bonus/render_2_bonus.c \
	bonus/render_bonus.c \
	bonus/utils_2_bonus.c \
	bonus/utils_bonus.c \
	bonus/enemy_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C libft bonus
	make -C minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDE) $(MLX_FLAGS)

bonus: $(OBJS_BONUS)
	make -C libft
	make -C libft bonus
	make -C minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_BONUS) $(LIBFT) $(INCLUDE) $(MLX_FLAGS)

clean:
	make -C libft clean
	make -C minilibx-linux clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.SECONDARY: $(OBJS) $(OBJS_BONUS)
.PHONY: clean fclean all re bonus

