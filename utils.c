/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:03:41 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/24 03:14:05 by yaharkat         ###   ########.fr       */
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
	free(line_map);
}

void	load_sprites(char *sprite_name, int nb_frame, void **sprite,
		t_solong *data)
{
	int		i;
	char	*path;
	char	*tmp;
	int		unused;

	i = -1;
	while (++i < nb_frame)
	{
		tmp = ft_strdup(sprite_name);
		if (nb_frame > 1)
		{
			path = join_paths(tmp, i);
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

void	print_game_state(t_solong *data)
{
	write(1, "\e[1;1H\e[2J", 11);
	ft_fprintf(STDOUT_FILENO, "\033[1m%s\033[0m\n\n", data->title);
	print_map(data);
	ft_fprintf(STDOUT_FILENO, "\n\033[33mMoves: \033[0m%d\n", data->moves);
	if (data->exit_reached)
		ft_fprintf(STDOUT_FILENO, "\033[32mYou won!!\n\033[0m");
	if (data->lost)
		ft_fprintf(STDOUT_FILENO, "\033[31mYou lost!!\n\033[0m");
}

void	draw_sprite(t_solong *data, int x, int y, void *sprite)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, sprite, x
		* SPRITE_SIZE, y * SPRITE_SIZE + HEADER_OFFSET);
}
