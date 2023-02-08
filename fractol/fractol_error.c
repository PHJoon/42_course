/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:42:16 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 16:14:13 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(char *s)
{
	printf("%s\n", s);
	printf("---------------------------------------------------------------");
	printf("\n\n");
	printf("\t./fractol julia\n");
	printf("\t./fractol mandelbrot\n\n");
	printf("\tif you want to draw julia set\n\n");
	printf("\t  ./fractol julia param1 param2\n");
	printf("\t  param1 is the real part of the complex number c\n");
	printf("\t  param2 is the imaginary part of the complex number c\n");
	printf("\t  if you do not input param1 or param2\n");
	printf("\t  param1 will be -0.79\n");
	printf("\t  param2 will be 0.15\n");
	printf("\n\n");
	printf("\tif you want to draw mandelbrot set\n\n");
	printf("\t  ./fractol mandelbrot\n");
	printf("\t  mandelbrot set do not require params\n\n");
	printf("---------------------------------------------------------------");
	printf("\n");
	exit(0);
}
