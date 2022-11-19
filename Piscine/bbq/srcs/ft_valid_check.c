/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwook <sungwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:09:38 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 10:34:07 by sungwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_row(char **map, int row_cnt)
{
	int		f_line;
	int		l_len;
	int		i;

	f_line = 0;
	while (map[1][f_line])
		f_line++;
	i = 1;
	while (i <= row_cnt)
	{
		l_len = 0;
		while (map[i][l_len])
		{
			if (!(map[i][l_len] == ft_empty(map) || map[i][l_len] \
				== ft_obs(map) || map[i][l_len] == ft_fill(map) || \
				map[i][l_len] == '\n'))
				return (0);
			l_len++;
		}
		if (map[i][l_len - 1] != '\n' || l_len != f_line)
			return (0);
		i++;
	}
	return (1);
}

int	check_firstline(char **map)
{
	char	empty;
	char	obs;
	char	fill;

	empty = ft_empty(map);
	obs = ft_obs(map);
	fill = ft_fill(map);
	if (!map[0])
		return (0);
	if (ft_strlen(map[0]) < 5)
		return (0);
	if (check_firstline_num(map) == 0)
		return (0);
	if (empty == obs || obs == fill || fill == empty)
		return (0);
	if (empty < 32 || empty > 126)
		return (0);
	if (obs < 32 || obs > 126)
		return (0);
	if (fill < 32 || fill > 126)
		return (0);
	return (1);
}

int	check_firstline_num(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map[0][i])
		i++;
	while (j < i - 4)
	{
		if (map[0][j] < '0' || map[0][j] > '9')
			return (0);
		j++;
	}
	return (1);
}

int	valid_check(char **map)
{
	int	j;
	int	k;

	j = 0;
	if (!check_firstline(map) || !check_row(map, ft_int_row(map)))
	{
		ft_putstr("map error\n");
		k = ft_int_row(map) + 1;
		while (j < k)
		{
			free(map[j]);
			j++;
		}
		free(map);
		return (0);
	}
	return (1);
}
