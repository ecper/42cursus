/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:01:06 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/07 18:37:46 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_position_data *data, double c_re, double c_im)
{
	double	temp;
	int		iter;

	iter = 0;
	while ((data->x * data->x + data->y * data->y <= 4) && (iter < PER_ITER))
	{
		temp = data->x * data->x - data->y * data->y + c_re;
		data->y = 2 * data->x * data->y + c_im;
		data->x = temp;
		iter++;
	}
	return (iter);
}

int	mandelbrot(t_position_data *data)
{
	int		iter;
	double	temp;

	data->c_re = data->x;
	data->c_im = data->y;
	iter = 0;
	while ((data->x0 * data->x0 + data->y0 * data->y0 <= 4)
		&& (iter < PER_ITER))
	{
		temp = data->x0 * data->x0 - data->y0 * data->y0 + data->c_re;
		data->y0 = 2 * data->x0 * data->y0 + data->c_im;
		data->x0 = temp;
		iter++;
	}
	return (iter);
}

int	burning_ship(t_position_data *data)
{
	int		iter;
	double	temp;

	data->c_re = data->x;
	data->c_im = data->y;
	iter = 0;
	while ((data->x0 * data->x0 + data->y0 * data->y0 <= 4)
		&& (iter < PER_ITER))
	{
		temp = data->x0 * data->x0 - data->y0 * data->y0 + data->c_re;
		data->y0 = fabs(2 * data->x0 * data->y0) + data->c_im;
		data->x0 = temp;
		iter++;
	}
	return (iter);
}
