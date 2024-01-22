/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:22:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/22 22:38:55 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_solong **data)
{
	(*data) = ft_calloc(1, sizeof(t_solong));
	if (!(*data))
		exit(EXIT_FAILURE);
	(*data)->mlx_ptr = mlx_init();
	(*data)->mlx_win = NULL;
	(*data)->collect = 0;
	(*data)->collectibles = 0;
	(*data)->exit = 0;
	(*data)->exit_reached = false;
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
}

void	init_player(int row, int col, t_solong *data)
{
	data->p_x = col;
	data->p_y = row;
	data->player++;
}

void	load_sprites(char *sprite_name, int nb_frame, void **sprite,
		t_solong *data)
{
	int		i;
	char	*path;
	char	*tmp;
	int		unused;

	i = 0;
	tmp = ft_strdup(sprite_name);
	while (++i < nb_frame)
	{
		if (nb_frame > 1)
		{
			path = ft_strjoin(tmp, "_");
			path = ft_strjoin(path, ft_itoa(i));
			path = ft_strjoin(path, ".xpm");
			sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr, path, &unused,
					&unused);
		}
		else
		{
			path = ft_strjoin(sprite_name, ".xpm");
			*sprite = mlx_xpm_file_to_image(data->mlx_ptr, path, &unused,
					&unused);
		}
		free(path);
	}
}
