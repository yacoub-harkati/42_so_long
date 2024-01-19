/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:15:14 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/18 17:13:21 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int read_height(char *map_name, t_map *map)
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
		cleanup_exit_error(map);
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

void read_map_items(t_map *map)
{
    int i = 0;
    int j;

    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            char cell = map->map[i][j];
            if (cell == 'C')
                map->collect++;
            else if (cell == 'P')
                set_player_position(map, i, j);
            else if (cell == 'E')
                map->exit++;
            else if (cell != '1' && cell != '0')
                handle_invalid_map(map);
            j++;
        }
        i++;
    }
    map->collectibles = map->collect;
}

void set_player_position(t_map *map, int i, int j)
{
    map->p_x = i;
    map->p_y = j;
    map->player++;
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
