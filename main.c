/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:34:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 02:50:19 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int render_game(t_solong *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (data->exit_reached)
	{
		// Won logic
		mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 10, 0x00FFFFFF, "You won!");
		mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 30, 0x00FFFFFF, "Press ESC to exit");
	}
	else
		render_game_logic(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	*data;

	init_struct(&data);
	init_title(data, av);
	check_and_parse_map(ac, av, data);
	init_sprite(data);
	init_window(data);
	print_game_state(data);
	hook_register(data);
	mlx_loop_hook(data->mlx_ptr, render_game, data);
	mlx_loop(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
