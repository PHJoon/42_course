/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:25:18 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/08/27 22:40:36 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	num_to_char(int x)
{
	char	ch_num[2];

	ch_num[0] = (x / 10) + '0';
	ch_num[1] = (x % 10) + '0';
	write(1, ch_num, 2);
}

void	ft_print_comb2(void)
{
	int		num_1;
	int		num_2;
	char	c[2];

	c[0] = ',';
	c[1] = ' ';
	num_1 = 0;
	num_2 = 1;
	while (num_1 <= 98)
	{	
		num_2 = num_1 + 1;
		while (num_2 <= 99)
		{
			num_to_char(num_1);
			write(1, &c[1], 1);
			num_to_char(num_2);
			if (num_1 != 98 || num_2 != 99)
				write(1, c, 2);
			num_2++;
		}
		num_1++;
	}
}
