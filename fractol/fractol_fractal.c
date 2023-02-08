/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:40:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/01/28 14:01:25 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_var	*set_fractal_num(t_var *var)
{
	if (var->mandelbrot == 1)
	{	
		var->z_r = 0;
		var->z_i = 0;
		var->c_r = ((var->pix_x - var->center_x) * \
		((var->x_max - var->x_min) / WIDTH)) - 0.3 - var->mouse_x;
		var->c_i = ((var->pix_y - var->center_y) * \
		((var->y_max - var->y_min) / HEIGHT)) - var->mouse_y;
		var->c_i *= -1;
	}
	else if (var->julia == 1)
	{
		var->z_r = ((var->pix_x - var->center_x) * \
		((var->x_max - var->x_min) / WIDTH)) - var->mouse_x;
		var->z_i = ((var->pix_y - var->center_y) * \
		((var->y_max - var->y_min) / HEIGHT)) - var->mouse_y;
		var->z_i *= -1;
	}
	var->iter = 0;
	return (var);
}

static void	do_julia(t_var *var)
{
	double	tmp;

	var = set_fractal_num(var);
	while (var->iter < var->max_iter)
	{
		var->z_r_sq = var->z_r * var->z_r;
		var->z_i_sq = var->z_i * var->z_i;
		if (var->z_r_sq + var->z_i_sq >= 4)
			break ;
		tmp = var->z_r_sq - var->z_i_sq + var->c_r;
		var->z_i = 2 * var->z_r * var->z_i + var->c_i;
		var->z_r = tmp;
		var->iter++;
	}
	my_mlx_pixel_put(var, var->pix_x, var->pix_y, make_color(var));
}

static void	do_mandelbrot(t_var *var)
{
	double	tmp;

	var = set_fractal_num(var);
	while (var->iter < var->max_iter)
	{
		var->z_r_sq = var->z_r * var->z_r;
		var->z_i_sq = var->z_i * var->z_i;
		if (var->z_r_sq + var->z_i_sq >= 4)
			break ;
		tmp = var->z_r_sq - var->z_i_sq + var->c_r;
		var->z_i = 2 * var->z_r * var->z_i + var->c_i;
		var->z_r = tmp;
		var->iter++;
	}
	my_mlx_pixel_put(var, var->pix_x, var->pix_y, make_color(var));
}

void	draw_fractal(t_var *var)
{
	if ((int)var->zoom % 3 == 1)
		var->max_iter += 30;
	var->pix_x = 0;
	while (var->pix_x <= WIDTH)
	{
		var->pix_y = 0;
		while (var->pix_y <= HEIGHT)
		{
			if (var->julia == 1)
				do_julia(var);
			else if (var->mandelbrot == 1)
				do_mandelbrot(var);
			var->pix_y++;
		}
		var->pix_x++;
	}
}
