/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:26 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/22 02:54:12 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_solong
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		map_fd;
	size_t	height;
	size_t	width;
	int		player;
	int		exit;
	int		collect;
	int		collectibles;
	bool	exit_reached;
	int		p_x;
	int		p_y;
	int		moves;
	char	**map;
	char	**map_cpy;
	t_list	*map_lst;
}			t_solong;

void		init_struct(t_solong **data);
void		check_and_parse(int ac, char **av, t_solong *data);
bool		check_args(int ac, char **av);
bool		fill_map_lst(t_solong *data);
bool		check_rectangular(t_solong *data);
void		convert_lst(t_solong *data);
bool		check_map_elements(t_solong *data);
void		init_player(int x, int y, t_solong *data);
bool		check_elem_count(t_solong *data);
void		flood_fill_map(t_solong *data, size_t x, size_t y);
bool		check_map_surrounded_walls(t_solong *data);
#endif