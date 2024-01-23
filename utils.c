/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:03:41 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 01:25:27 by yaharkat         ###   ########.fr       */
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

void	load_sprites(char *sprite_name, int nb_frame, void **sprite,
		t_solong *data)
{
	int		i;
	char	*path;
	char	*tmp;
	int		unused;

	i = 0;
	while (++i < nb_frame)
	{
		tmp = ft_strdup(sprite_name);
		if (nb_frame > 1)
		{
			path = ft_strjoin(tmp, "_");
			path = ft_strjoin(path, ft_itoa(i));
			path = ft_strjoin(path, ".xpm");
			sprite[i] = mlx_xpm_file_to_image(data->mlx_ptr, path, &unused,
					&unused);
		}
		else
		{
			path = ft_strjoin(tmp, ".xpm");
			*sprite = mlx_xpm_file_to_image(data->mlx_ptr, path, &unused,
					&unused);
		}
		free(path);
	}
}
