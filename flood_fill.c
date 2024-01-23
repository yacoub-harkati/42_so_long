/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:45:55 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 01:23:13 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_valid_point(t_point p, t_solong *data, char **map)
{
	char	current;

	if (p.x < 0 || p.x >= (int)data->width || p.y < 0
		|| p.y >= (int)data->height)
		return (true);
	current = map[p.y][p.x];
	if (current == WALL || current == ENEMY || current == 'V')
		return (true);
	return (false);
}

static bool	is_collectible_or_exit(t_point p, t_solong *data, char **map)
{
	char	current;

	current = map[p.y][p.x];
	if (current == COLLECTIBLE)
		data->collect--;
	if (current == PLAYER)
		init_player(p.x, p.y, data);
	if (current == EXIT)
	{
		data->exit_reached = true;
		return (true);
	}
	return (false);
}

static void	add_neighbours_to_stack(t_point p, int *top, t_point *stack)
{
	stack[(*top)++] = (t_point){p.x + 1, p.y};
	stack[(*top)++] = (t_point){p.x - 1, p.y};
	stack[(*top)++] = (t_point){p.x, p.y + 1};
	stack[(*top)++] = (t_point){p.x, p.y - 1};
}

void	flood_fill_map(t_solong *data, int col, int row)
{
	t_point	*stack;
	int		top;
	char	**map;
	t_point	p;

	top = 0;
	map = data->map_cpy;
	stack = malloc(sizeof(t_point) * data->width * data->height);
	stack[top++] = (t_point){col, row};
	while (top > 0)
	{
		p = stack[--top];
		if (is_valid_point(p, data, map))
			continue ;
		if (is_collectible_or_exit(p, data, map))
			continue ;
		map[p.y][p.x] = 'V';
		add_neighbours_to_stack(p, &top, stack);
	}
	free(stack);
	free_matrix(map);
}
