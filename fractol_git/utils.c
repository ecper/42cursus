/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:03:11 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/19 09:01:20 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, t_data *data)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iteration >= MAX_ITER)
		return (0x000000);
	t = (double)iteration / MAX_ITER;
	red = (int)(data->r_set * (1 - t) * 255);
	green = (int)(data->g_set * (1 - t) * 255);
	blue = (int)(data->b_set * (1 - t) * 255);
	return ((red << 16) | (green << 8) | blue);
}

void	change_color_set(int type, t_data *data)
{
	if (type == 1)
	{
		data->r_set = 200;
		data->g_set = 10;
		data->b_set = 10;
	}
	else if (type == 2)
	{
		data->r_set = 166;
		data->g_set = 150;
		data->b_set = 179;
	}
	else
	{
		data->r_set = 9;
		data->g_set = 15;
		data->b_set = 8.5;
	}
	data->rerender = 0;
}
