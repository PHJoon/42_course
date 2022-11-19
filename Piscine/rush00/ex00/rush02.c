/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seminkim <seminkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:44:45 by seminkim          #+#    #+#             */
/*   Updated: 2022/08/27 18:47:19 by seminkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int x, char first, char middle, char last)
{
	int	num;

	num = 0;
	ft_putchar(first);
	if (x != 1)
	{
		while (num < x - 2)
		{
			ft_putchar(middle);
			num ++;
		}
		ft_putchar(last);
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
			if (line == 1)
			{
				ft_print(x, 'A', 'B', 'A');
			}
			else if (line == y)
			{
				ft_print(x, 'C', 'B', 'C');
			}
			else
			{
				ft_print(x, 'B', ' ', 'B');
			}
			line ++;
		}
	}
}
