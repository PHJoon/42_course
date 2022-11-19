/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seminkim <seminkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:44:38 by seminkim          #+#    #+#             */
/*   Updated: 2022/08/27 18:46:15 by seminkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int x, char side, char middle)
{
	int	num;

	num = 0;
	ft_putchar(side);
	if (x != 1)
	{
		while (num < x - 2)
		{
			ft_putchar(middle);
			num ++;
		}
		ft_putchar(side);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	line;

	line = 1;
	if (x >= 1 && y >= 1)
	{
		while (line <= y)
		{
			if (line == 1 || line == y)
			{
				ft_print(x, 'o', '-');
			}
			else
			{
				ft_print(x, '|', ' ');
			}
			line ++;
		}
	}
}
