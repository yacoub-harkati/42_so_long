/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:15:14 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/18 16:13:36 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int read_height(char *map_name, t_data *data, t_map *map)
{
	int fd;
	char *line;
	int read;
	int height;

	height = 0;
	fd = open(map_name, O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_fprintf(2, "Error\nCan't open map");
		cleanup_exit_error(data, map);
	}
	while (1)
	{
		read = get_next_line(fd, &line);
		height++;
		free(line);
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

void read_map_items(t_map *map, t_data *data)
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
			{
				map->p_x = i;
				map->p_y = j;
				map->player++;
			}
			else if (map->map[i][j] == 'E')
				map->exit++;
			else if (map->map[i][j] == '1' || map->map[i][j] == '0')
			{
				j++;
				continue;
			}
			else
				ft_fprintf(2, "Error\nInvalid map");
				cleanup_exit_error(data, map);
			j++;
		}
		i++;
	}
	map->collectibles = map->collect;
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
