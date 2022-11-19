/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:17:51 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/07 22:02:07 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	min;
	int	max;
	int	i;
	int	size;
	int	*new;

	i = 0;
	min = -3;
	max = 10;
	size = max - min;
	new = ft_range(min, max);
	while (i < size)
	{
		printf("%d\n", new[i]);
		i++;
	}
}
