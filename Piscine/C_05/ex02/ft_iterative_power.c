/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:55:26 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/05 16:57:14 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		res = nb;
		while (power > 1)
		{
			res = res * nb;
			power--;
		}
		return (res);
	}
}
