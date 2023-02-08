/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_atod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:01:03 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 14:23:42 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	under_decimalpoint(char *s, size_t i)
{
	size_t	j;
	double	res;

	j = 0;
	res = 0;
	while (s[i])
	{
		res *= 10;
		res += s[i] - '0';
		i++;
		j++;
	}
	res /= pow(10, j);
	return (res);
}

double	ft_atod(char *s)
{
	size_t	len;
	size_t	i;
	double	flag;
	double	res;

	len = ft_strlen(s);
	flag = 1;
	res = 0;
	i = 0;
	if (s[0] == '+' || s[0] == '-')
	{
		if (s[0] == '-')
			flag = -1;
		i++;
	}
	while (s[i] && s[i] != '.')
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	if (s[i] == '.')
		res += under_decimalpoint(s, i + 1);
	return (res * flag);
}
