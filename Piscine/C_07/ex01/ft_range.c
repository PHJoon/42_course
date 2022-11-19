/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:40:38 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/10 13:00:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	size;
	int			*arr;
	int			i;

	i = 0;
	if (min >= max)
		return (0);
	size = (long long)max - (long long)min;
	arr = (int *)malloc(sizeof(int) * (size));
	if (!arr)
		return (0);
	while (i < size)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
