/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:14:12 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/03 13:09:19 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_floor(t_solong *data, int x, int y)
{
	draw_sprite(data, x, y, data->floor_sprite);
}

void	render_enemy(t_solong *data, int x, int y)
{
	static int	i;
	static int	call_count;
	int			render_delay;

	if (data->width * data->height >= 200)
		render_delay = 100;
	else
		render_delay = 700;
	if (call_count > render_delay)
	{
		i = (i + 1) % 3;
		call_count = 0;
	}
	else
		call_count++;
	draw_sprite(data, x, y, data->enemy_sprite[i]);
}

void	render_player(t_solong *data, int x, int y)
{
	static int	i;
	static int	call_count;
	int			render_delay;

	if (data->width * data->height >= 200)
		render_delay = 100;
	else
		render_delay = 450;
	if (call_count > render_delay)
	{
		i = (i + 1) % 4;
		call_count = 0;
	}
	else
		call_count++;
	if (data->p_dir == 0)
		draw_sprite(data, x, y, data->player_sprite_left[i]);
	else if (data->p_dir == 1)
		draw_sprite(data, x, y, data->player_sprite_right[i]);
}

void	render_game_moves(t_solong *data)
{
	char		*str;
	char		*temp;
	static int	moves;

	str = ft_itoa(data->moves);
	temp = ft_strjoin(ft_strdup("Moves: "), str);
	if (data->moves > moves)
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 14, 0x00FFFFFF, temp);
	free(str);
	free(temp);
	moves = data->moves;
}
