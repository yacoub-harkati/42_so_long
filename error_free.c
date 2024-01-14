/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:35:19 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/14 23:34:11 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **mx)
{
	int i;

	if (!mx)
		return;
	i = 0;
	while (mx[i])
	{
		free(mx[i]);
		i++;
	}
	free(mx[i]);
	free(mx);
}

void cleanup_exit_error(t_data *data, t_map *map)
{
	if (map)
	{
		free_map(map->map);
		free_map(map->map_cpy);
		free(map);
	}
	if (data)
		free(data);
	exit(EXIT_FAILURE);
}
