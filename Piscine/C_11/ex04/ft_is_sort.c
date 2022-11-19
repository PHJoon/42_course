/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:15:23 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/13 16:32:29 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sort_flag;

	i = 0;
	sort_flag = 0;
	if (length <= 2)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
		{
			if (sort_flag == -1)
				return (0);
			sort_flag = 1;
		}
		else if (f(tab[i], tab[i + 1]) > 0)
		{
			if (sort_flag == 1)
				return (0);
			sort_flag = -1;
		}
		i++;
	}
	return (1);
}
