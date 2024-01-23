/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:06:09 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/23 05:36:19 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_hook(int keycode, t_solong *data)
{
	(void)keycode;
	cleanup(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keydown_hook(int keycode, t_solong *data)
{
	if (keycode == XK_Escape)
		close_hook(0, data);
	else
		handle_action(keycode, data);
	return (0);
}

void	hook_register(t_solong *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, keydown_hook, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, close_hook, data);
}
