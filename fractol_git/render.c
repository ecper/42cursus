/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:16:05 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/21 14:27:15 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_render_type(t_position_data *position_data, t_data *data)
{
	if (data->render_type == TYPE_JULIA)
		return (julia(position_data, data->c_re, data->c_im));
	else if (data->render_type == TYPE_BURNING_SHIP)
		return (burning_ship(position_data));
	else
		return (mandelbrot(position_data));
}

int	render(t_data *data)
{
	int						px;
	int						py;
	static t_position_data	position_data[HEIGHT][WIDTH];

	py = 0;
	while (py < HEIGHT)
	{
		px = 0;
		while (px < WIDTH)
		{
			if (!data->rerender)
				init_position_data(&position_data[py][px], data, px, py);
			position_data[py][px].iter
				+= get_render_type(&position_data[py][px], data);
			my_mlx_pixel_put(&data->img, px, py,
				get_color(position_data[py][px].iter, data));
			px++;
		}
		py++;
	}
	if (!data->rerender)
		data->rerender = 1;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
