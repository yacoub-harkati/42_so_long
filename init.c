/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:53:42 by yaharkat          #+#    #+#             */
/*   Updated: 2023/12/31 16:55:10 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_struct(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
	{
		ft_fprintf(2, "Error\nMalloc failed\n");
		exit(EXIT_FAILURE);
	}
	(*data)->mlx_ptr = mlx_init();
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	(*data)->map = malloc(sizeof(t_map));
	if (!(*data)->map)
	{
		ft_fprintf(2, "Error\nMalloc failed\n");
		exit(EXIT_FAILURE);
	}
	(*data)->map->height = 0;
	(*data)->map->width = 0;
	(*data)->map->player = 0;
	(*data)->map->exit = 0;
	(*data)->map->collect = 0;
	(*data)->map->wall = 0;
	(*data)->map->map = NULL;
}