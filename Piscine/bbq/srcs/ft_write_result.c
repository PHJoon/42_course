/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwook <sungwook@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:52:40 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/15 10:34:27 by sungwook         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_write_result(char **result, int row)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (result == 0)
	{
		write(1, "map error", 9);
		return ;
	}
	while (i < row + 1)
	{
		ft_putstr(result[i]);
		i++;
	}
	while (j < row + 1)
	{
		free(result[j]);
		j++;
	}
	free(result);
}
