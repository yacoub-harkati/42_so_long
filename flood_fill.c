/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 03:59:54 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 04:18:13 by yaharkat         ###   ########.fr       */
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

void	flood_fill_map(t_solong *data, int x, int y)
{
	t_queue	*queue;
	char	**map;
	t_point	p;

	queue = create_queue();
	map = data->map_cpy;
	enqueue(queue, (t_point){x, y});
	while (queue->front != NULL)
	{
		p = dequeue(queue);
		if (is_valid_point(p, data, map))
			continue ;
		if (is_collectible_or_exit(p, data, map))
			continue ;
		map[p.y][p.x] = 'V';
		enqueue(queue, (t_point){p.x + 1, p.y});
		enqueue(queue, (t_point){p.x - 1, p.y});
		enqueue(queue, (t_point){p.x, p.y + 1});
		enqueue(queue, (t_point){p.x, p.y - 1});
	}
	free(queue);
}
