/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwook <sungwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:22:02 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 10:33:56 by sungwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_col_len(char **map)
{
	int	row_len;
	int	col_len;

	row_len = ft_int_row(map);
	col_len = 0;
	while (map[1][col_len])
		col_len++;
	return (col_len);
}

int	get_sqr_len(char **map)
{
	int	row_len;
	int	col_len;

	row_len = ft_int_row(map);
	col_len = get_col_len(map);
	if (row_len > col_len)
		return (col_len);
	return (row_len);
}
