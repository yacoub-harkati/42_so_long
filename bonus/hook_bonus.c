/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:06:09 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/24 17:07:59 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_hook(int keycode, t_solong *data)
{
	if (keycode == 0)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	close_destroy_hook(t_solong *data)
{
	mlx_loop_end(data->mlx_ptr);
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
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask,
		close_destroy_hook, data);
}
