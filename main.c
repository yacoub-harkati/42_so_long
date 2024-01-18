/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:34:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/18 15:39:16 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_data *data;
    t_map *map;
    if (ac != 2)
        return EXIT_FAILURE;
    data = NULL;
    map = NULL;
    check_args(ac, av);
    init_struct(&data, &map, av[1]);
    
    mlx_loop(data->mlx_ptr);
    return (EXIT_SUCCESS);
}
