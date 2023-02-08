/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:40:45 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 15:45:42 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_var *var, int x, int y, int color)
{
	char	*dst;

	dst = var->addr + (y * var->line_l + x * (var->bpp / 8));
	*(unsigned int *)dst = color;
}

void	start_mlx(t_var *var, char **argv)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, WIDTH, HEIGHT, argv[1]);
	var->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	var->addr = mlx_get_data_addr(var->img, &var->bpp, \
	&var->line_l, &var->endian);
	draw_fractal(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	mlx_key_hook(var->win, keyboard_event, var);
	mlx_mouse_hook(var->win, mouse_event, var);
	mlx_hook(var->win, 17, 0, exit_hook, var);
	mlx_loop(var->mlx);
}
