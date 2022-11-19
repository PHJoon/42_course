/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:05:43 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/10 17:21:45 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*re;
	int	size;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	re = (int *)malloc(sizeof(int) * size);
	if (!re)
		return (-1);
	while (i < size)
	{
		re[i] = min;
		min++;
		i++;
	}
	*range = re;
	return (size);
}
