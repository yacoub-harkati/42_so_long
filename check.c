/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:29:24 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/22 02:56:27 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_and_parse(int ac, char **av, t_solong *data)
{
	if (!check_args(ac, av))
		exit(EXIT_FAILURE);
	data->map_fd = open(av[1], O_RDONLY);
	if (data->map_fd < 0)
	{
		ft_fprintf(2, "Error\nCan't open map\n");
		exit(EXIT_FAILURE);
	}
	fill_map_lst(data);
	if (!check_rectangular(data) || !check_map_elements(data)
		|| !check_elem_count(data))
		exit(EXIT_FAILURE);
	data->width = ft_strlen(data->map[0]);
	data->collect = data->collectibles;
	if (!check_map_surrounded_walls(data))
		exit(EXIT_FAILURE);
	printf("|%d| |%d|\n", data->p_x, data->p_y);
	flood_fill_map(data, data->p_x, data->p_y);
	printf("collectibles: %d\n", data->collectibles);
	printf("collect: %d\n", data->collect);
	printf("exit reached: %s\n", data->exit_reached ? "true" : "false");
}

bool	check_args(int ac, char **av)
{
	size_t	mapfile_len;

	if (ac != 2)
	{
		ft_fprintf(2, "Error\nInvalid number of arguments\n");
		return (false);
	}
	mapfile_len = ft_strlen(av[1]);
	if (mapfile_len <= 4 || ft_strncmp(".ber", &av[1][mapfile_len - 4], 4))
	{
		ft_fprintf(2, "Error\nInvalid map extension\n");
		return (false);
	}
	return (true);
}

bool	check_rectangular(t_solong *data)
{
	t_list	*map;
	size_t	i;

	map = data->map_lst;
	data->height = ft_lstsize(map);
	data->width = ft_strlen(map->content);
	i = 0;
	while (map)
	{
		if (ft_strlen(map->content) != (data->width - (data->height == i + 1)))
		{
			ft_fprintf(2, "Error\nMap is not rectangular\n");
			return (false);
		}
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
			if (data->map[x][y] == 'C')
				data->collectibles++;
			else if (data->map[x][y] == 'P')
				init_player(x, y, data);
			else if (data->map[x][y] == 'E')
				data->exit++;
			else if (data->map[x][y] != '1' && data->map[x][y] != '0')
			{
				ft_fprintf(2, "Error\nInvalid map |%c|\n", data->map[x][y]);
				return (false);
			}
		}
	}
	return (true);
}

bool	check_elem_count(t_solong *data)
{
	if (data->collectibles < 1 || data->exit != 1 || data->player != 1)
	{
		ft_fprintf(2, "Error\nInvalid map: only 1>=C & 1P & 1E are valid\n");
		return (false);
	}
	return (true);
}
