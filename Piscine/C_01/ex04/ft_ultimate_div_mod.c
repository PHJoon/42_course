/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:55:58 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/08/28 17:14:46 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp1;
	int	temp2;

	temp1 = *a;
	temp2 = *b;
	if (temp2 == 0)
		return ;
	else
	{
		*a = temp1 / temp2;
		*b = temp1 % temp2;
	}
}
