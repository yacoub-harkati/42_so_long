/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:48:21 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 06:02:02 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}

void	cleanup(t_solong *data)
{
	if (data->map)
		free_matrix(data->map);
	if (data->map_cpy)
		free_matrix(data->map_cpy);
	ft_lstclear(&(data->map_lst), free);
	free(data->title);
	if (data->sprites_loaded)
		free_sprites(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data);
}

void	free_sprites(t_solong *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx_ptr, data->player_sprite_left[i]);
		mlx_destroy_image(data->mlx_ptr, data->player_sprite_right[i]);
		mlx_destroy_image(data->mlx_ptr, data->exit_sprite[i]);
		mlx_destroy_image(data->mlx_ptr, data->collectible_sprite[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		mlx_destroy_image(data->mlx_ptr, data->enemy_sprite[i]);
		i++;
	}
	mlx_destroy_image(data->mlx_ptr, data->floor_sprite);
	mlx_destroy_image(data->mlx_ptr, data->wall_sprite);
}

void	printf_error_clean(char *str, t_solong *data)
{
	ft_fprintf(STDERR_FILENO, "\033[1;31mError\033[0m\n%s", str);
	if (data)
		cleanup(data);
	exit(EXIT_FAILURE);
}
