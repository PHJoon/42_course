/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:42:09 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/01/28 13:42:11 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mlx_reset(t_var *var)
{
	var->mlx = NULL;
	var->win = NULL;
	var->img = NULL;
	var->addr = NULL;
	var->bpp = 0;
	var->line_l = 0;
	var->endian = 0;
}

static void	math_reset(t_var *var)
{
	var->x_max = 2;
	var->x_min = -2;
	var->y_max = 2;
	var->y_min = -2;
	var->pix_x = 0;
	var->pix_y = 0;
	var->z_r = 0;
	var->z_i = 0;
	var->c_r = -0.79;
	var->c_i = 0.15;
	var->iter = 0;
	var->max_iter = 200;
	var->zoom = 1;
	var->center_x = WIDTH / 2;
	var->center_y = HEIGHT / 2;
	var->mouse_x = 0;
	var->mouse_y = 0;
}

static void	var_reset(t_var *var, char **argv, int frac)
{
	mlx_reset(var);
	math_reset(var);
	if (frac == 1)
	{
		var->julia = 1;
		var->mandelbrot = 0;
		if (argv[2])
		{
			var->c_r = ft_atod(argv[2]);
			if (argv[3])
				var->c_i = ft_atod(argv[3]);
		}
	}
	else if (frac == 2)
	{
		var->mandelbrot = 1;
		var->julia = 0;
	}
}

t_var	*var_init(char **argv, int frac)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
	{
		perror("malloc error!");
		exit(0);
	}
	var_reset(var, argv, frac);
	return (var);
}
