/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:53:42 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/14 02:59:07 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int read_height(char *map_name)
{
	int fd;
	char *line;
	int read;
	int height;

	height = 0;
	fd = open(map_name, O_RDONLY, 0644);
	while (1)
	{
		read = get_next_line(fd, &line);
		height++;
		if (!read)
			break;
	}
	close(fd);
	return height;
}

void read_width(t_map *map)
{
	int width;

	width = 0;
	while (map->map[0][width])
		width++;
	map->width = width;
}

void read_map_items(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->collect++;
			else if (map->map[i][j] == 'P')
				map->player++;
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == '1' || map->map[i][j] == '0')
			{
				j++;
				continue;
			}
			else
				exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
}

bool is_map_rectangle(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != map->width)
			return false;
		i++;
	}
	return true;
}

bool is_map_surrounded_by_walls(t_map *map)
{
	int col;
	int row;

	col = 0;
	row = 0;
	while (map->map[row])
	{
		if (row == 0 || row == (map->height - 1))
		{
			while (map->map[row][col])
			{
				if (map->map[row][col] != '1')
					return false;
				col++;
			}
		}
		else
		{
			if (map->map[row][0] != '1' || map->map[row][map->width - 1] != '1')
				return false;
		}
		row++;
	}
	return true;
}

void read_map(t_map *map, char *map_name)
{
	int fd;
	int row;
	char *line;
	char *final_line;
	int read;

	read = 0;
	row = 0;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	map->map[map->height] = NULL;
	fd = open(map_name, O_RDONLY, 0644);
	final_line = NULL;
	while (1)
	{
		read = get_next_line(fd, &line);
		final_line = ft_strjoin(final_line, line);
		if (!read)
			break;
	}
	map->map = ft_split(final_line, '\n');
	close(fd);
}
void check_map(t_map *map)
{
	if (map->exit != 1 || map->collect < 1 || map->player != 1)
		exit(EXIT_FAILURE);
	if (!is_map_rectangle(map) || !is_map_surrounded_by_walls(map))
		exit(EXIT_FAILURE);
}

void init_struct(t_data **data, t_map **map, char *map_name)
{
	init_map(map, map_name);
	*data = malloc(sizeof(t_data));
	(*data)->mlx_ptr = mlx_init();
	(*data)->win_ptr = mlx_new_window((*data)->mlx_ptr, (*map)->width, (*map)->height, "So long");
}

void init_map(t_map **map, char *map_name)
{
	*map = malloc(sizeof(t_map));
	(*map)->height = read_height(map_name);
	(*map)->width = 0;
	(*map)->collect = 0;
	(*map)->player = 0;
	(*map)->map_cpy = NULL;
	read_map(*map, map_name);
	read_width(*map);
	read_map_items(*map);
	check_map(*map);
}
