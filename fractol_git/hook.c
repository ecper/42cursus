/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 06:19:07 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/20 22:10:57 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	if (mousecode == 4)
	{
		data->zoom_mag *= ZOOM;
		zoom(data, x, y, ZOOM);
	}
	else if (mousecode == 5)
	{
		data->zoom_mag /= ZOOM;
		zoom(data, x, y, 1 / ZOOM);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	else if (keycode == W_KEY)
		change_color_set(COLOR_SET_1, data);
	else if (keycode == A_KEY)
		change_color_set(COLOR_SET_2, data);
	else if (keycode == S_KEY)
		change_color_set(COLOR_SET_3, data);
	else if (keycode == LEFT_ARROW_KEY || keycode == RIGHT_ARROW_KEY
		|| keycode == TOP_ARROW_KEY || keycode == DOWN_ARROW_KEY)
		move(data, keycode, MOVE);
	return (0);
}
