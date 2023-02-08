/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:41:07 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 15:46:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_in(int x, int y, t_var *var)
{
	var->x_max /= 1.3;
	var->x_min /= 1.3;
	var->y_max /= 1.3;
	var->y_min /= 1.3;
	var->zoom += 2;
	var->mouse_x += (var->center_x - x) * (var->x_max - var->x_min) / WIDTH;
	var->mouse_y += (var->center_y - y) * (var->y_max - var->y_min) / HEIGHT;
}

static void	zoom_out(int x, int y, t_var *var)
{
	var->x_max *= 1.3;
	var->x_min *= 1.3;
	var->y_max *= 1.3;
	var->y_min *= 1.3;
	var->zoom -= 2;
	var->mouse_x -= (x - var->center_x) * (var->x_max - var->x_min) / WIDTH;
	var->mouse_y -= (y - var->center_y) * (var->y_max - var->y_min) / HEIGHT;
}

int	mouse_event(int keycode, int x, int y, t_var *var)
{
	mlx_mouse_get_pos(var->win, &x, &y);
	if (keycode == WHEEL_UP)
		zoom_in(x, y, var);
	else if (keycode == WHEEL_DOWN)
	{
		if (var->zoom == -1)
			return (0);
		zoom_out(x, y, var);
	}
	mlx_clear_window(var->mlx, var->win);
	var->img = NULL;
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	var->addr = mlx_get_data_addr(var->img, &var->bpp, \
	&var->line_l, &var->endian);
	draw_fractal(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	return (0);
}

int	keyboard_event(int keycode, t_var *var)
{
	(void)var;
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	exit_hook(t_var *var)
{
	(void)var;
	exit(0);
}
