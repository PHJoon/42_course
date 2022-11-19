/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_first_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:56:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 11:00:01 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	buf_fill(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	return (buf[i - 1]);
}

char	buf_obs(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	return (buf[i - 2]);
}

char	buf_empty(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
		i++;
	return (buf[i - 3]);
}
