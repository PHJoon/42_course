/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:27:54 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/04 07:03:35 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_int_char(int nb)
{
	char	x;

	x = (nb % 10) + '0';
	if (nb >= 10)
	{
		ft_int_char(nb / 10);
		ft_int_char(nb % 10);
	}
	else
		write(1, &x, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_int_char(-nb);
	}
	else
		ft_int_char(nb);
}		
