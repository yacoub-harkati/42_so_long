/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:34:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 06:34:28 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_game(t_solong *data)
{
	if (data->exit_reached)
	{
		mlx_string_put(data->mlx_ptr, data->mlx_win, data->width * 32 / 2 - 42,
			data->height * 32 / 2 - 10, 0x00FFFFFF, "You won!");
		mlx_string_put(data->mlx_ptr, data->mlx_win, data->width * 32 / 2 - 42,
			data->height * 32 / 2 + 10, 0x00FFFFFF, "Press ESC to exit");
	}
	else if (data->lost)
	{
		mlx_string_put(data->mlx_ptr, data->mlx_win, data->width * 32 / 2 - 42,
			data->height * 32 / 2 - 10, 0x00FFFFFF, "You lost!");
		mlx_string_put(data->mlx_ptr, data->mlx_win, data->width * 32 / 2 - 42,
			data->height * 32 / 2 + 10, 0x00FFFFFF, "Press ESC to exit");
	}
	else
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		render_game_moves(data);
		render_game_logic(data);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	*data;

	init_struct(&data);
	init_title(data, av);
	check_and_parse_map(ac, av, data);
	init_window(data);
	init_sprite(data);
	print_game_state(data);
	hook_register(data);
	mlx_loop_hook(data->mlx_ptr, render_game, data);
	mlx_loop(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}