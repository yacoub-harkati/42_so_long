/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:26 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/12 15:35:27 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <X11/keysym.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct s_map
{
	int height;
	int width;
	int player;
	int exit;
	int collect;
	int wall;
	char **map;
} t_map;

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int endian;
	int bits_per_pixel;
	int size_line;
} t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img *img;
	t_map *map;
} t_data;


void check_args(int ac, char **av);

#endif