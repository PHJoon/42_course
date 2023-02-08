/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_check_argv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:21:34 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 15:08:03 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_fractal(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	if (ft_strncmp(s, "JULIA", 5) == 0)
		return (1);
	else if (ft_strncmp(s, "MANDELBROT", 10) == 0)
		return (2);
	return (-1);
}

static int	ft_isdot(char s)
{
	if (s == 46)
		return (1);
	return (0);
}

static int	check_julia_params(char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		else
		{
			if (ft_isdigit(str[i]) == 0)
			{
				if (ft_isdot(str[i]) == 0)
					return (0);
				else
					flag++;
			}
			i++;
		}
	}
	if (flag > 1)
		return (0);
	return (1);
}

int	check_argv(char **argv)
{
	int	frac;

	frac = check_fractal(argv[1]);
	if (frac == -1)
		error_msg("arguments error!\n");
	if (frac == 1)
	{
		if (argv[2])
		{
			if (check_julia_params(argv[2]) == 0)
				error_msg("invalid params(julia set)\n");
			if (argv[3])
			{
				if (check_julia_params(argv[3]) == 0)
					error_msg("invalid params(julia set)\n");
			}
		}
	}		
	if (frac == 2 && argv[2] != NULL)
		error_msg("mandelbrot set do not require params\n");
	return (frac);
}
