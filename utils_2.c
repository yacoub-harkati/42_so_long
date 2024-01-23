/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:39:12 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 06:57:29 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join_paths(char *tmp, int i)
{
	char	*path;
	char	*num;
	char	*tmp_path;

	num = ft_itoa(i + 1);
	tmp_path = ft_strjoin(tmp, "_");
	path = ft_strjoin(tmp_path, num);
	path = ft_strjoin(path, ".xpm");
	free(num);
	return (path);
}
