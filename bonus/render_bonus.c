/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:06:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/03 13:10:29 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_game_logic(t_solong *data)
{
	int	col;
	int	row;
	int	c_count;

	row = -1;
	c_count = 0;
	while (data->map[++row])
	{
		col = -1;
		while (data->map[row][++col])
		{
			render_floor(data, col, row);
			if (data->map[row][col] == WALL)
				render_wall(data, col, row);
			else if (data->map[row][col] == COLLECTIBLE)
				render_collectible(data, col, row, c_count++);
			else if (data->map[row][col] == EXIT)
				render_exit(data, col, row);
			else if (data->map[row][col] == PLAYER)
				render_player(data, col, row);
			else if (data->map[row][col] == ENEMY)
				render_enemy(data, col, row);
		}
	}
}

void	render_wall(t_solong *data, int x, int y)
{
	draw_sprite(data, x, y, data->wall_sprite);
}

void	render_collectible(t_solong *data, int x, int y, int index)
{
	static int	i[50000];
	static int	call_count[50000];
	int			render_delay;

	if (data->width * data->height >= 200)
		render_delay = 100;
	else
		render_delay = 1000;
	if (call_count[index] > render_delay)
	{
		i[index] = (i[index] + 1) % 4;
		call_count[index] = 0;
	}
	else
		call_count[index]++;
	draw_sprite(data, x, y, data->collectible_sprite[i[index]]);
}

void	render_exit(t_solong *data, int x, int y)
{
	static int	i;
	static int	call_count;
	static bool	rendered;
	int			render_delay;

	if (data->width * data->height >= 200)
		render_delay = 100;
	else
		render_delay = 500;
	if (data->collectibles == 0)
	{
		if (!rendered && call_count > render_delay)
		{
			i = (i + 1) % 4;
			if (i == 3)
				rendered = true;
			call_count = 0;
		}
		else
			call_count++;
	}
	draw_sprite(data, x, y, data->exit_sprite[i]);
}
