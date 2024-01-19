/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:15:14 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/19 00:36:00 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(t_map *map, char *map_name)
{
	int fd;
	char *line[2];
	int read;

	read = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	map->map[map->height] = NULL;
	fd = open(map_name, O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_fprintf(2, "Error\nCan't open map");
		cleanup_exit_error(map);
	}
	line[1] = NULL;
	while (1)
	{
		read = get_next_line(fd, &line[0]);
		line[1] = ft_strjoin(line[1], line[0]);
		free(line[0]);
		if (!read)
			break;
	}
	map->map = ft_split(line[1], '\n');
	close(fd);
}

void cpy_map(t_map *map)
{
	int i;

	i = 0;
	map->map_cpy = malloc(sizeof(char *) * (map->height + 1));
	map->map_cpy[map->height] = NULL;
	while (map->map[i])
	{
		map->map_cpy[i] = ft_strdup(map->map[i]);
		i++;
	}
}

void flood_fill_map(t_map *map, int row, int col)
{
	char current;

	if (row < 0 || row >= map->height || col < 0 || col >= map->width)
		return;
	current = map->map_cpy[row][col];
	if (current == '1' || current == 'F')
		return;
	if (current == 'C')
		map->collect--;
	if (current == 'E')
	{
		map->exit_reached = true;
		return;
	}
	map->map_cpy[row][col] = 'F';
	flood_fill_map(map, row - 1, col);
	flood_fill_map(map, row + 1, col);
	flood_fill_map(map, row, col - 1);
	flood_fill_map(map, row, col + 1);
}

void check_map(t_map *map)
{
	if (map->exit != 1 || map->collect < 1 || map->player != 1)
	{
		ft_fprintf(2, "Error\nInvalid map");
		cleanup_exit_error(map);
	}
	if (!is_map_rectangle(map) || !is_map_surrounded_by_walls(map))
	{
		ft_fprintf(2, "Error\nInvalid map");
		cleanup_exit_error(map);
	}
	cpy_map(map);
	flood_fill_map(map, map->p_x, map->p_y);
	if (!map->exit_reached || !!map->collect)
	{
		ft_fprintf(2, "Error\nInvalid map");
		cleanup_exit_error(map);
	}
}
