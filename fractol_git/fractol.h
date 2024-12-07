/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:12:42 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/20 22:12:01 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 4000
# define PER_ITER 100
# define ZOOM 1.1
# define MOVE 0.1

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define Q_KEY 113
# define R_KEY 114
# define ESC_KEY 65307
# define CROSS_BUTTON 17
# define LEFT_ARROW_KEY 65361
# define TOP_ARROW_KEY 65362
# define RIGHT_ARROW_KEY 65363
# define DOWN_ARROW_KEY 65364
# define TYPE_JULIA 1
# define TYPE_BURNING_SHIP 2
# define TYPE_MANDELBROT 3
# define COLOR_SET_1 1
# define COLOR_SET_2 2
# define COLOR_SET_3 3

# define MIN_RE -2.0
# define MIN_IM -1.5
# define RWIDTH 4
# define IHEIGHT 3
# include "minilibx-linux/mlx.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// 画像データを管理する構造体
typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img_data;

// メインデータ構造体
typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img_data	img;
	double		min_re;
	double		min_im;
	double		c_re;
	double		c_im;
	double		zoom_mag;
	int			rerender;
	int			render_type;
	double		r_set;
	double		g_set;
	double		b_set;
}				t_data;

typedef struct s_position_data
{
	double		x;
	double		y;
	double		x0;
	double		y0;
	double		c_re;
	double		c_im;
	int			iter;
}				t_position_data;

void			move(t_data *data, int arrow_type, double factor);
int				close_window(t_data *data);
void			zoom(t_data *data, int x, int y, double factor);
int				julia(t_position_data *data, double c_re, double c_im);
int				mandelbrot(t_position_data *data);
double			ft_atof(const char *str);
int				ft_isdouble(const char *str);
void			change_color_set(int type, t_data *data);
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int				mouse_hook(int mousecode, int x, int y, t_data *data);
int				key_hook(int keycode, t_data *data);
int				get_color(int iteration, t_data *data);
void			init_data(t_data *data, int argc, char **argv);
int				ft_strcmp(const char *s1, const char *s2);
void			init_position_data(t_position_data *position_data, t_data *data,
					int px, int py);
double			calc_max(double min, double zoom_mag, int is_re);
int				burning_ship(t_position_data *data);
void			change_render_type(int type, t_data *data);
int				render(t_data *data);
#endif