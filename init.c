/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:22:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/05 09:22:03 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_solong **data)
{
	(*data) = ft_calloc(1, sizeof(t_solong));
	if (!(*data))
		exit(EXIT_FAILURE);
	(*data)->mlx_ptr = NULL;
	(*data)->mlx_win = NULL;
	(*data)->collect = 0;
	(*data)->collectibles = 0;
	(*data)->exit = 0;
	(*data)->exit_reached = false;
	(*data)->sprites_loaded = false;
	(*data)->lost = false;
	(*data)->height = 0;
	(*data)->width = 0;
	(*data)->map = NULL;
	(*data)->map_cpy = NULL;
	(*data)->map_lst = NULL;
	(*data)->map_fd = -1;
	(*data)->p_x = -1;
	(*data)->p_y = -1;
	(*data)->moves = 0;
	(*data)->player = 0;
}

void	init_sprite(t_solong *data)
{
	load_sprites("textures/xpm/w", 1, &(data->wall_sprite), data);
	load_sprites("textures/xpm/f", 1, &(data->floor_sprite), data);
	load_sprites("textures/xpm/pr", 4, data->player_sprite_right, data);
	load_sprites("textures/xpm/pl", 4, data->player_sprite_left, data);
	load_sprites("textures/xpm/c", 4, data->collectible_sprite, data);
	load_sprites("textures/xpm/e", 4, data->exit_sprite, data);
	load_sprites("textures/xpm/i", 3, data->enemy_sprite, data);
	data->sprites_loaded = true;
}

void	init_player(int col, int row, t_solong *data)
{
	data->p_x = col;
	data->p_y = row;
	data->player++;
}

void	init_title(t_solong *data, char **av)
{
	char	*title;

	title = ft_strrchr(av[1], '/');
	if (title != NULL)
	{
		data->title = ft_strjoin(ft_strdup("So long | "), title + 1);
		return ;
	}
	data->title = ft_strjoin(ft_strdup("So long | "), av[1]);
}

void	init_window(t_solong *data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->width * SPRITE_SIZE,
			data->height * SPRITE_SIZE + HEADER_OFFSET, data->title);
}
