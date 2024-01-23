/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:25:12 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 03:29:52 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_action(int keycode, t_solong *data)
{
	if (keycode == ARROW_UP || keycode == UP)
		move_player(0, -1, data);
	else if (keycode == ARROW_DOWN || keycode == DOWN)
		move_player(0, 1, data);
	else if (keycode == ARROW_LEFT || keycode == LEFT)
	{
		data->p_dir = 0;
		move_player(-1, 0, data);
	}
	else if (keycode == ARROW_RIGHT || keycode == RIGHT)
	{
		data->p_dir = 1;
		move_player(1, 0, data);
	}
}

void	move_player(int x, int y, t_solong *data)
{
	if (data->map[data->p_y + y][data->p_x + x] == FLOOR)
		handle_player(x, y, data);
	else if (data->map[data->p_y + y][data->p_x + x] == COLLECTIBLE)
	{
		handle_player(x, y, data);
		data->collectibles--;
	}
	else if (data->map[data->p_y + y][data->p_x + x] == EXIT
		&& data->collectibles == 0)
	{
		handle_player(x, y, data);
		data->exit_reached = true;
	}
	else if (data->map[data->p_y + y][data->p_x + x] == ENEMY)
	{
		ft_fprintf(STDOUT_FILENO, "You lost\n");
		exit(EXIT_SUCCESS);
	}
	print_game_state(data);
}

void	handle_player(int x, int y, t_solong *data)
{
	data->map[data->p_y][data->p_x] = FLOOR;
	data->map[data->p_y + y][data->p_x + x] = PLAYER;
	data->p_x += x;
	data->p_y += y;
	data->moves++;
}

void	print_map(t_solong *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		ft_fprintf(STDOUT_FILENO, "%s\n", data->map[i]);
		i++;
	}
}
