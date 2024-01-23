/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:45:20 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 05:18:06 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_map_surrounded_walls(t_solong *data)
{
	size_t	x;
	size_t	y;

	x = -1;
	while (data->map[++x])
	{
		y = -1;
		if (x == 0 || x == data->height - 1)
		{
			while (data->map[x][++y])
			{
				if (data->map[x][y] != WALL)
					printf_error_clean("Map not surrounded by walls\n", data);
			}
		}
		else if (data->map[x][0] != '1' || data->map[x][data->width - 1] != '1')
			printf_error_clean("Map not surrounded by walls\n", data);
	}
	return (true);
}
