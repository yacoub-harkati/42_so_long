/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 01:25:12 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 01:34:17 by yaharkat         ###   ########.fr       */
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
		move_player(-1, 0, data);
	else if (keycode == ARROW_RIGHT || keycode == RIGHT)
		move_player(1, 0, data);
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
	print_map(data);
	printf("\nplayer pos: x: %d y: %d\n", data->p_x, data->p_y);
	printf("collectibles: %d\n", data->collectibles);
	ft_fprintf(1, "moves: %d\n", data->moves);
}

void	handle_player(int x, int y, t_solong *data)
{
	data->map[data->p_y][data->p_x] = FLOOR;
	data->map[data->p_y + y][data->p_x + x] = PLAYER;
	data->p_x += x;
	data->p_y += y;
	data->moves++;
}

void	clearScreen(void)
{
	const char	*CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";

	write(1, CLEAR_SCREEN_ANSI, 11);
}

void	print_map(t_solong *data)
{
	int	i;

	i = 0;
	clearScreen();
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}
