/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:22:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/22 03:08:49 by yaharkat         ###   ########.fr       */
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
