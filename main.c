/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:34:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/21 23:06:13 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_solong	*data;

	init_struct(&data);
	check_and_parse(ac, av, data);
	mlx_loop(data->mlx_ptr);
	return (EXIT_SUCCESS);
}
