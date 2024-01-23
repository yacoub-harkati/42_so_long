/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:34:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 01:32:06 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_solong	*data;
	
	init_struct(&data);
	init_title(data, av);
	check_and_parse_map(ac, av, data);
	init_sprite(data);
	init_window(data);
	print_map(data);
	hook_register(data);
	mlx_loop(data->mlx_ptr);
	return (EXIT_SUCCESS);
}
