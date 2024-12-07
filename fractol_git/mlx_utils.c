/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:02:28 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/20 22:11:24 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	calc_max(double min, double zoom_mag, int is_re)
{
	double	max;

	if (!is_re)
		max = (IHEIGHT / zoom_mag) + min;
	else
		max = (RWIDTH / zoom_mag) + min;
	return (max);
}

void	zoom(t_data *data, int x, int y, double factor)
{
	double	re_x;
	double	im_y;
	double	max_re;
	double	max_im;

	max_re = calc_max(data->min_re, data->zoom_mag, 1);
	max_im = calc_max(data->min_im, data->zoom_mag, 0);
	re_x = data->min_re + x * ((max_re - data->min_re) / WIDTH);
	im_y = data->min_im + y * ((max_im - data->min_im) / HEIGHT);
	data->min_re = re_x + (data->min_re - re_x) / factor;
	data->min_im = im_y + (data->min_im - im_y) / factor;
	data->rerender = 0;
}

void	move(t_data *data, int arrow_type, double factor)
{
	if (arrow_type == LEFT_ARROW_KEY)
		data->min_re = data->min_re - (factor / data->zoom_mag);
	else if (arrow_type == RIGHT_ARROW_KEY)
		data->min_re = data->min_re + (factor / data->zoom_mag);
	else if (arrow_type == TOP_ARROW_KEY)
		data->min_im = data->min_im - (factor / data->zoom_mag);
	else if (arrow_type == DOWN_ARROW_KEY)
		data->min_im = data->min_im + (factor / data->zoom_mag);
	data->rerender = 0;
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
