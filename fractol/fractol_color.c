/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fratol_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:01:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 14:25:33 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	make_color(t_var *var)
{
	double	zn;
	int		c;
	int		color;

	zn = log(log(var->z_r_sq + var->z_i_sq)) / log(2);
	zn = var->iter + 1 - zn;
	c = (int)zn;
	if (var->iter == var->max_iter)
		color = create_trgb(0, 0, 0, 0);
	else
		color = create_trgb(c % 64, c % 256, (c * 3) % 256, 200);
	return (color);
}
