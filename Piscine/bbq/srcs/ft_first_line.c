/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwook <sungwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:00:40 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 10:33:54 by sungwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	ft_fill(char **map)
{
	char	fill;

	fill = map[0][ft_strlen(map[0]) - 2];
	return (fill);
}

char	ft_obs(char **map)
{
	char	obs;

	obs = map[0][ft_strlen(map[0]) - 3];
	return (obs);
}

char	ft_empty(char **map)
{
	char	empty;

	empty = map[0][ft_strlen(map[0]) - 4];
	return (empty);
}

int	ft_int_row(char **map)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < ft_strlen(map[0]) - 4)
	{
		res *= 10;
		res += map[0][i] - '0';
		i++;
	}
	return (res);
}

int	ft_get_row(char *buf)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (buf[i] != '\n')
		i++;
	while (j < i - 3)
	{
		res *= 10;
		res += buf[j] - '0';
		j++;
	}
	return (res);
}
