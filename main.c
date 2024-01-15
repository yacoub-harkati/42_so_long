/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 20:34:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/15 16:08:19 by yaharkat         ###   ########.fr       */
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

    printf("map width: %d\n", map->width);
    printf("map height: %d\n", map->height);
    printf("map player: %d\n", map->player);
    printf("map collect: %d\n", map->collect);
    printf("map collect: %d\n", map->collectibles);
    printf("map exit: %d\n", map->exit);
    printf("exit: %d\n", map->exit_reached);
    printf("exit: %s\n", map->exit_reached == 1 ? "true" : "false");
    mlx_loop(data->mlx_ptr);
    return (EXIT_SUCCESS);
}
