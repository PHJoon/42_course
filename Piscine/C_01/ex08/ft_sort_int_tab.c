/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:17:52 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/08/28 17:13:59 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	now;
	int	temp;
	int	i;

	now = 0;
	while (now < size - 1)
	{
		i = 0;
		while (now + i <= size - 1)
		{
			if (tab[now] > tab[now + i])
			{
				temp = tab[now];
				tab[now] = tab[now + i];
				tab[now + i] = temp;
			}
			i++;
		}
		now++;
	}
}
