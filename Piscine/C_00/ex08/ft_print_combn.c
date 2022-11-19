/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:32:09 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/08/29 20:33:53 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_combn(int now_depth, int goal_depth, char box[], int num)
{
	if (now_depth == goal_depth)
	{
		write(1, box, goal_depth);
		if (box[0] != 10 - goal_depth + '0')
			write(1, ", ", 2);
		return ;
	}
	else
	{	
		while (num < 10)
		{
			box[now_depth] = num + '0';
			ft_combn(now_depth + 1, goal_depth, box, num + 1);
			num++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	box[9];

	ft_combn(0, n, box, 0);
}
