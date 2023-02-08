/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:16 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 15:08:47 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define WIDTH 800
# define HEIGHT 800

# define WHEEL_UP 4
# define WHEEL_DOWN 5

# define ESC 53

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
	double	z_r;
	double	z_i;
	double	z_r_sq;
	double	z_i_sq;
	double	c_r;
	double	c_i;
	double	iter;
	double	max_iter;
	double	zoom;
	int		pix_x;
	int		pix_y;
	double	center_x;
	double	center_y;
	double	mouse_x;
	double	mouse_y;
	int		mandelbrot;
	int		julia;
}				t_var;

double	ft_atod(char *s);
int		check_argv(char **argv);
int		make_color(t_var *var);
void	error_msg(char *s);
void	draw_fractal(t_var *var);
int		mouse_event(int keycode, int x, int y, t_var *var);
int		keyboard_event(int keycode, t_var *var);
int		exit_hook(t_var *var);
void	my_mlx_pixel_put(t_var *var, int x, int y, int color);
void	start_mlx(t_var *var, char **argv);
t_var	*var_init(char **argv, int frac);

#endif
