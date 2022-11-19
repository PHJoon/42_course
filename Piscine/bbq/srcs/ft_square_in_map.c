/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_in_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwook <sungwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:53:21 by sungwook          #+#    #+#             */
/*   Updated: 2022/09/15 10:33:59 by sungwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**ft_draw_map(char **map, char **result, int *get)
{
	int	i;
	int	j;
	int	col;
	int	row;
	int	sqr_len;

	col = get[0];
	row = get[1];
	sqr_len = get[2];
	i = 0;
	while (i < sqr_len)
	{
		j = 0;
		while (j < sqr_len)
		{
			result[row + i][col + j] = ft_fill(map);
			j++;
		}
		i++;
	}
	return (result);
}

int	ft_find_square(char **map, int row, int col, int sqr_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < sqr_len)
	{
		j = 0;
		while (j < sqr_len)
		{
			if (map[row + i][col + j] == ft_obs(map))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	*ft_get_get(int row, int col, int sqr_len)
{
	int	*get;

	get = (int *)malloc(sizeof(int) * 3);
	if (!get)
		return (0);
	get[0] = col;
	get[1] = row;
	get[2] = sqr_len;
	return (get);
}

int	*ft_find_start(char **map, int sqr_len, int row_len)
{
	int	col;
	int	row;

	while (sqr_len > 0)
	{
		row = 1;
		while (row < (row_len - sqr_len))
		{
			col = 0;
			while (col < ((get_col_len(map)) - sqr_len))
			{
				if (ft_find_square(map, row, col, sqr_len) == TRUE)
					return (ft_get_get(row, col, sqr_len));
				col++;
			}
			row++;
		}
		sqr_len--;
	}
	return (0);
}

char	**ft_square_in_map(char **map, int row, int col)
{
	int		i;
	int		sqr_len;
	int		*get;
	char	**result;

	i = 0;
	result = (char **)malloc(sizeof(char *) * (row + 1));
	if (!result)
		return (0);
	while (i < row + 1)
	{
		result[i] = (char *)malloc(sizeof(char) * col + 2);
		if (!result[i])
			return (0);
		result[i] = ft_strcpy(result[i], map[i]);
		i++;
	}
	sqr_len = get_sqr_len(map);
	get = ft_find_start(map, sqr_len, row);
	if (get == 0)
		return (0);
	result = ft_draw_map(map, result, get);
	free(get);
	return (result);
}
