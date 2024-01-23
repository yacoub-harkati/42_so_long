/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:14:12 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 04:52:40 by yaharkat         ###   ########.fr       */
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

	if (call_count > 700)
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

	if (call_count > 450)
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
	char	*str;
	char	*temp;

	str = ft_itoa(data->moves);
	temp = ft_strjoin(ft_strdup("Moves: "), str);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 14, 0x00FFFFFF, temp);
	free(str);
	free(temp);
}
