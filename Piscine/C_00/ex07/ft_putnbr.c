/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:44:08 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/08/27 15:40:54 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	set(int x)
{
	char	num[10];
	int		i;

	i = 9;
	while (x / 10 != 0)
	{
		num[i] = (x % 10) + '0';
		x = x / 10;
		i--;
	}
	num[i] = x + '0';
	while (i <= 9)
	{
		write(1, &num[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	minus;

	minus = '-';
	if (nb >= 0)
		set(nb);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		nb = -(nb);
		write(1, &minus, 1);
		set(nb);
	}
}
