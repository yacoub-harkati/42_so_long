/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:26 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/19 00:30:37 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdbool.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

typedef struct s_map
{
	int height;
	int width;
	int player;
	int exit;
	int collect;
	int collectibles;
	bool exit_reached;
	int p_x;
	int p_y;
	char **map;
	char **map_cpy;
} t_map;

typedef struct s_item_render
{
	void *img;
	int width;
	int height;
} t_item_render;

typedef struct s_img
{
	t_item_render *character_left[5];
	t_item_render *character_right[5];
	t_item_render *exit[4];
	t_item_render *coin[4];
	t_item_render *wall;
	t_item_render *floor;
} t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img *imgs;
} t_data;

void check_args(int ac, char **av);
void init_struct(t_data **data, t_map **map, char *map_name);
void init_map(t_map **map, char *map_name);
void read_map(t_map *map, char *map_name);
void cpy_map(t_map *map);
void flood_fill_map(t_map *map, int row, int col);
void check_map(t_map *map);
bool is_map_surrounded_by_walls(t_map *map);
bool is_map_rectangle(t_map *map);
void read_map_items(t_map *map);
void read_width(t_map *map);
int read_height(char *map_name, t_map *map);
void cleanup_exit_error(t_map *map);
void cleanup_exit(t_data *data, t_map *map);
void handle_invalid_map(t_map *map);
void init_images(t_data *data, t_img *imgs);
void set_player_position(t_map *map, int i, int j);

#endif