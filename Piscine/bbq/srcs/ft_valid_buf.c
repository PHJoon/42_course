/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:46:59 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 11:10:42 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_ncnt(char *buf)
{
	int	i;
	int	cnt_n;

	i = 0;
	cnt_n = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			cnt_n++;
		i++;
	}
	if (cnt_n != ft_get_row(buf) + 1)
		return (0);
	return (1);
}

int	check_char(char *buf)
{
	char	empty;
	char	obs;
	char	fill;

	empty = buf_empty(buf);
	obs = buf_obs(buf);
	fill = buf_fill(buf);
	if (ft_strlen(buf) < 5)
		return (0);
	if (buf[0] < '0' || buf[0] > '9')
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

int	valid_buf(char *buf)
{
	if (!check_ncnt(buf) || !check_char(buf))
	{
		ft_putstr("map error\n");
		free(buf);
		return (0);
	}
	return (1);
}
