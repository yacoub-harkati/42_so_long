/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:29:24 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/02 02:43:22 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_and_parse_map(int ac, char **av, t_solong *data)
{
	if (!check_args(ac, av))
		exit(EXIT_FAILURE);
	data->map_fd = open(av[1], O_RDONLY);
	if (data->map_fd < 0)
		printf_error_clean("Can't open map file\n", data);
	fill_map_lst(data);
	if (!data->map_lst)
		printf_error_clean("Invalid map: map empty\n", data);
	if (!check_rectangular(data) || !check_map_elements(data)
		|| !check_elem_count(data))
		exit(EXIT_FAILURE);
	data->width = ft_strlen(data->map[0]);
	data->collect = data->collectibles;
	if (!check_map_surrounded_walls(data))
		exit(EXIT_FAILURE);
	flood_fill_map(data, data->p_y, data->p_x);
	if (!data->exit_reached)
		printf_error_clean("Invalid map: couldn't reach exit\n", data);
	if (!!data->collect)
		printf_error_clean("Invalid map: couldn't collect all collectibles\n",
			data);
	data->exit_reached = false;
}

bool	check_args(int ac, char **av)
{
	size_t	mapfile_len;

	if (ac != 2)
		printf_error_clean("Number of arguments is not valid\n", NULL);
	mapfile_len = ft_strlen(av[1]);
	if (mapfile_len <= 4 || ft_strncmp(".ber", &av[1][mapfile_len - 4], 4))
		printf_error_clean("Invalid map file\n", NULL);
	return (true);
}

bool	check_rectangular(t_solong *data)
{
	t_list	*map;
	size_t	i;

	map = data->map_lst;
	data->width = ft_strlen(map->content);
	data->height = ft_lstsize(map);
	i = 0;
	while (map)
	{
		if (ft_strlen(map->content) != (data->width - (data->height == i + 1)))
			printf_error_clean("Invalid map: not rectangular\n", data);
		map = map->next;
		i++;
	}
	return (true);
}

bool	check_map_elements(t_solong *data)
{
	size_t	x;
	size_t	y;

	x = -1;
	convert_lst(data);
	while (data->map[++x])
	{
		y = -1;
		while (data->map[x][++y])
		{
			if (data->map[x][y] == COLLECTIBLE)
				data->collectibles++;
			else if (data->map[x][y] == PLAYER && data->player == 0)
				init_player(x, y, data);
			else if (data->map[x][y] == EXIT)
				data->exit++;
			else if (data->map[x][y] == ENEMY)
				data->enemy_count++;
			else if (data->map[x][y] != WALL && data->map[x][y] != FLOOR
				&& data->map[x][y] != ENEMY)
				printf_error_clean("Invalid map: invalid element\n", data);
		}
	}
	return (true);
}

bool	check_elem_count(t_solong *data)
{
	if (data->collectibles < 1 || data->exit != 1 || data->player != 1)
		printf_error_clean("Invalid map: missing elements\n", data);
	return (true);
}
