/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:19 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/18 17:13:27 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **mx)
{
	int i;

	if (!mx)
		return;
	i = 0;
	while (mx[i])
	{
		free(mx[i]);
		i++;
	}
	free(mx[i]);
	free(mx);
}

void cleanup_exit_error( t_map *map)
{
	if (map)
	{
		free_map(map->map);
		free_map(map->map_cpy);
		free(map);
	}
	exit(EXIT_FAILURE);
}

void cleanup_exit(t_data *data, t_map *map)
{
	if (map)
	{
		free_map(map->map);
		free_map(map->map_cpy);
		free(map);
	}
	if (data)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data);
	}
}


void handle_invalid_map(t_map *map)
{
    ft_fprintf(2, "Error\nInvalid map");
    cleanup_exit_error(map);
}