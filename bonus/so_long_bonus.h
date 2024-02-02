/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:26 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/02 02:39:04 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define FLOOR '0'
# define ENEMY 'I'
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define HEADER_OFFSET 20
# define SPRITE_SIZE 32
# define ENEMY_MOVE_DELAY 1500

typedef struct s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct s_solong
{
	void				*mlx_ptr;
	void				*mlx_win;
	char				*title;
	int					map_fd;
	size_t				height;
	size_t				width;
	int					player;
	int					exit;
	int					collect;
	int					collectibles;
	bool				exit_reached;
	bool				lost;
	bool				sprites_loaded;
	int					p_x;
	int					p_y;
	int					p_dir;
	int					moves;
	int					enemy_count;
	t_point				*enemy_pos;
	char				**map;
	char				**map_cpy;
	t_list				*map_lst;
	void				*wall_sprite;
	void				*floor_sprite;
	void				*player_sprite_right[4];
	void				*player_sprite_left[4];
	void				*collectible_sprite[4];
	void				*exit_sprite[4];
	void				*enemy_sprite[3];
}						t_solong;

typedef struct s_queue_node
{
	t_point				point;
	struct s_queue_node	*next;
}						t_queue_node;

typedef struct s_queue
{
	t_queue_node		*front;
	t_queue_node		*rear;
}						t_queue;

// Initialization functions
void					init_struct(t_solong **data);
void					init_player(int row, int col, t_solong *data);
void					init_sprite(t_solong *data);
void					init_title(t_solong *data, char **av);
void					init_window(t_solong *data);
void					init_enemy(t_solong *data);

// Map parsing and checking functions
bool					check_args(int ac, char **av);
void					check_and_parse_map(int ac, char **av, t_solong *data);
void					fill_map_lst(t_solong *data);
bool					check_rectangular(t_solong *data);
void					convert_lst(t_solong *data);
bool					check_map_elements(t_solong *data);
bool					check_elem_count(t_solong *data);
void					flood_fill_map(t_solong *data, int x, int y);
bool					check_map_surrounded_walls(t_solong *data);

// Sprite loading function
void					load_sprites(char *sprite_name, int nb_frame,
							void **sprite, t_solong *data);

// Player movement functions
void					handle_action(int keycode, t_solong *data);
void					handle_player(int x, int y, t_solong *data);
void					move_player(int x, int y, t_solong *data);

// Rendering functions
void					print_map(t_solong *data);
void					print_game_state(t_solong *data);
void					draw_sprite(t_solong *data, int x, int y, void *sprite);
void					render_exit(t_solong *data, int x, int y);
void					render_collectible(t_solong *data, int x, int y,
							int index);
void					render_wall(t_solong *data, int x, int y);
int						render_game(t_solong *data);
void					render_game_logic(t_solong *data);
void					render_floor(t_solong *data, int x, int y);
void					render_enemy(t_solong *data, int x, int y);
void					render_player(t_solong *data, int x, int y);
void					render_game_moves(t_solong *data);
void					render_text(t_solong *data, char *text);

// Queue functions for flood fill algorithm
t_queue					*create_queue(void);
void					enqueue(t_queue *q, t_point point);
t_point					dequeue(t_queue *q);

// Hook registration and helper functions
void					hook_register(t_solong *data);
void					free_matrix(char **matrix);
void					cleanup(t_solong *data);
void					free_sprites(t_solong *data);
void					printf_error_clean(char *str, t_solong *data);
char					*join_paths(char *tmp, int i);
void					move_enemy(t_solong *data, int player_x, int player_y);
void					move_enemy_logic(t_solong *data, int i, int new_x,
							int new_y);
bool					should_update_enemy_pos(int delay);
void					move_enemy_direction(t_solong *data, int i, int dx,
							int dy);
#endif