/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:40:10 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 14:26:52 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	int		frac;
	t_var	*var;

	if (argc < 2 || argc > 5)
		error_msg("arguments error!");
	frac = check_argv(argv);
	var = var_init(argv, frac);
	start_mlx(var, argv);
	return (0);
}
