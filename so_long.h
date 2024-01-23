/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:26 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 01:01:40 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
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

typedef struct s_solong
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*title;
	int		map_fd;
	size_t	height;
	size_t	width;
	int		player;
	int		exit;
	int		collect;
	int		collectibles;
	bool	exit_reached;
	int		p_x;
	int		p_y;
	int		moves;
	char	**map;
	char	**map_cpy;
	t_list	*map_lst;
	void	*wall_sprite;
	void	*floor_sprite;
	void	*player_sprite_right[4];
	void	*player_sprite_left[4];
	void	*collectible_sprite[4];
	void	*exit_sprite[4];
	void	*enemy_sprite[3];
}			t_solong;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

void		init_struct(t_solong **data);
void		check_and_parse_map(int ac, char **av, t_solong *data);
bool		check_args(int ac, char **av);
bool		fill_map_lst(t_solong *data);
bool		check_rectangular(t_solong *data);
void		convert_lst(t_solong *data);
bool		check_map_elements(t_solong *data);
void		init_player(int row, int col, t_solong *data);
bool		check_elem_count(t_solong *data);
void		flood_fill_map(t_solong *data, int x, int y);
bool		check_map_surrounded_walls(t_solong *data);
void		init_sprite(t_solong *data);
void		load_sprites(char *sprite_name, int nb_frame, void **sprite,
				t_solong *data);
void		init_title(t_solong *data, char **av);
void		init_window(t_solong *data);
void		hook_register(t_solong *data);
void		free_matrix(char **matrix);
void		handle_action(int keycode, t_solong *data);
void		move_player(int x, int y, t_solong *data);
void		print_map(t_solong *data);
#endif