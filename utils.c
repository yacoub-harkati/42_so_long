/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:03:41 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/22 03:10:29 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	fill_map_lst(t_solong *data)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		get_next_line(data->map_fd, &line);
		if (line == NULL)
			return (false);
		if (data->map_lst == NULL)
			data->map_lst = ft_lstnew(line);
		else
			ft_lstadd_back(&(data->map_lst), ft_lstnew(line));
	}
	close(data->map_fd);
	return (true);
}

void	convert_lst(t_solong *data)
{
	t_list	*tmp;
	char	*line_map;

	tmp = data->map_lst;
	line_map = NULL;
	while (tmp)
	{
		line_map = ft_strjoin(line_map, tmp->content);
		tmp = tmp->next;
	}
	data->map = ft_split(line_map, '\n');
	data->map_cpy = ft_split(line_map, '\n');
	ft_lstclear(&(data->map_lst), free);
}

void	init_player(int x, int y, t_solong *data)
{
	data->p_x = x;
	data->p_y = y;
	data->player++;
}

void	flood_fill_map(t_solong *data, size_t x, size_t y)
{
	char current;

	if (x <= 0 || x >= data->width || y <= 0 || y >= data->height)
		return ;
	current = data->map_cpy[y][x];
	if (current == 'F' || current == '1')
		return ;
	if (current == 'C')
		data->collect--;
	else if (current == 'E')
	{
		data->exit_reached = true;
		data->map_cpy[y][x] = 'F';
		return ;
	}
	data->map_cpy[y][x] = 'F';
	flood_fill_map(data, x + 1, y);
	flood_fill_map(data, x - 1, y);
	flood_fill_map(data, x, y - 1);
	flood_fill_map(data, x, y + 1);
}
