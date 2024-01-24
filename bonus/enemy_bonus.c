/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:10:28 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/24 03:32:47 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy(t_solong *data, int player_x, int player_y)
{
	int	i;
	int	dx;
	int	dy;

	i = -1;
	if (!should_update_enemy_pos(ENEMY_MOVE_DELAY))
		return ;
	while (++i < data->enemy_count)
	{
		dx = data->enemy_pos[i].x - player_x;
		dy = data->enemy_pos[i].y - player_y;
		move_enemy_direction(data, i, dx, dy);
	}
	print_game_state(data);
}

void	move_enemy_logic(t_solong *data, int i, int new_x, int new_y)
{
	if (new_x >= 0 && new_x < (int)data->width && new_y >= 0
		&& new_y < (int)data->height && data->map[new_y][new_x] == FLOOR)
	{
		data->map[data->enemy_pos[i].y][data->enemy_pos[i].x] = FLOOR;
		data->map[new_y][new_x] = ENEMY;
		data->enemy_pos[i].x = new_x;
		data->enemy_pos[i].y = new_y;
	}
	else if (data->map[new_y][new_x] == PLAYER)
	{
		data->lost = true;
	}
}

void	move_enemy_direction(t_solong *data, int i, int dx, int dy)
{
	if (fabs((double)(dx)) > fabs((double)dy))
	{
		if (dx > 0)
			move_enemy_logic(data, i, data->enemy_pos[i].x - 1,
				data->enemy_pos[i].y);
		else
			move_enemy_logic(data, i, data->enemy_pos[i].x + 1,
				data->enemy_pos[i].y);
	}
	else
	{
		if (dy > 0)
			move_enemy_logic(data, i, data->enemy_pos[i].x, data->enemy_pos[i].y
				- 1);
		else
			move_enemy_logic(data, i, data->enemy_pos[i].x, data->enemy_pos[i].y
				+ 1);
	}
}

bool	should_update_enemy_pos(int delay)
{
	static int	call_count = 0;

	if (call_count > delay)
	{
		call_count = 0;
		return (true);
	}
	call_count++;
	return (false);
}

void	init_enemy(t_solong *data)
{
	int	i;
	int	j;
	int	enemy_index;

	i = -1;
	j = -1;
	enemy_index = -1;
	data->enemy_pos = malloc(sizeof(t_point) * data->enemy_count);
	if (!data->enemy_pos)
		printf_error_clean("Enemy Malloc failed\n", data);
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == ENEMY)
			{
				data->enemy_pos[++enemy_index].x = j;
				data->enemy_pos[enemy_index].y = i;
			}
		}
	}
}
