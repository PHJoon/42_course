/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:19:23 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/05 11:23:15 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_b(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (len(base) == 0 || len(base) == 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	write_base(char *base, int i)
{
	write(1, &base[i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	b_len;

	b_len = len(base);
	if (check_b(base) == 0)
		return ;
	if (nbr == -2147483648)
	{
		ft_putnbr_base(-2147483648 / b_len, base);
		ft_putnbr_base(-(-2147483648 % b_len), base);
	}
	else if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		ft_putnbr_base(nbr, base);
	}
	else if (nbr >= b_len)
	{
		ft_putnbr_base(nbr / b_len, base);
		ft_putnbr_base(nbr % b_len, base);
	}
	else
		write_base(base, nbr);
}
