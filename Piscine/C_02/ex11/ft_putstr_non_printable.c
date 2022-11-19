/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:33:01 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/07 12:12:50 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hexa(unsigned char str)
{
	write(1, &"0123456789abcdef"[(str / 16)], 1);
	write(1, &"0123456789abcdef"[(str % 16)], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			ft_hexa((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
