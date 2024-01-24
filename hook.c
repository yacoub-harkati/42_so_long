/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:06:09 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/24 04:08:02 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_hook(int keycode, t_solong *data)
{
	if (keycode == 0)
		mlx_loop_end(data->mlx_ptr);
	else
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
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, keydown_hook, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, close_hook,
		data);
}
