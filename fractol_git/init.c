/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:56:49 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/20 22:06:20 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_julia_params(int argc, char **argv, t_data *data)
{
	if ((argc == 3 || argc > 4) && (!ft_isdouble(argv[2])
			|| !ft_isdouble(argv[3])))
	{
		perror("error:put like this './fractol julia -0.7269 0.1889'");
		exit(0);
	}
	if (ft_isdouble(argv[2]) && ft_isdouble(argv[3]))
	{
		data->c_re = ft_atof(argv[2]);
		data->c_im = ft_atof(argv[3]);
	}
	else
	{
		data->c_re = -0.7269;
		data->c_im = 0.1889;
	}
}

static void	init_render_params(int argc, char **argv, t_data *data)
{
	if (argc < 2)
	{
		perror("error,put like this './fractol mandelbrot'\n");
		perror("select three option 'mandelbrot' 'julia' 'burning ship'\n");
		exit(0);
	}
	if (!ft_strcmp(argv[1], "julia"))
	{
		init_julia_params(argc, argv, data);
		data->render_type = TYPE_JULIA;
	}
	else if (!ft_strcmp(argv[1], "mandelbrot"))
		data->render_type = TYPE_MANDELBROT;
	else if (!ft_strcmp(argv[1], "burning ship"))
		data->render_type = TYPE_BURNING_SHIP;
	else
	{
		perror("select three option 'mandelbrot' 'julia' 'burning ship'\n");
		exit(0);
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FRACTOL");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	init_render_params(argc, argv, data);
	data->zoom_mag = 1.0;
	data->min_re = MIN_RE;
	data->min_im = MIN_IM;
	data->rerender = 0;
	data->r_set = 9;
	data->g_set = 15;
	data->b_set = 8.5;
}

void	init_position_data(t_position_data *position_data, t_data *data, int px,
		int py)
{
	position_data->x = data->min_re + ((calc_max(data->min_re, data->zoom_mag,
					1) - data->min_re) / WIDTH) * px;
	position_data->y = data->min_im + ((calc_max(data->min_im, data->zoom_mag,
					0) - data->min_im) / HEIGHT) * py;
	position_data->x0 = 0;
	position_data->y0 = 0;
	position_data->iter = 0;
}
