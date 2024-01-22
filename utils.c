/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:03:41 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/22 19:51:19 by yaharkat         ###   ########.fr       */
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

void	init_player(int row, int col, t_solong *data)
{
	data->p_x = col;
	data->p_y = row;
	data->player++;
}
