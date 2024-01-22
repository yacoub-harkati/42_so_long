/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:45:20 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/22 02:32:54 by yaharkat         ###   ########.fr       */
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
				if (data->map[x][y] != '1')
				{
					ft_fprintf(2, "Error\nMap not surrounded by walls\n");
					return (false);
				}
			}
		}
		else if (data->map[x][0] != '1' || data->map[x][data->width - 1] != '1')
		{
			ft_fprintf(2, "Error\nMap not surrounded by walls\n");
			return (false);
		}
	}
	return (true);
}
