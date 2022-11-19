/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do-op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:47:58 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/13 11:02:45 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_calculator(int a, char *str, int b)
{
	int	(*arr[5])(int, int);

	arr[0] = add;
	arr[1] = sub;
	arr[2] = mul;
	arr[3] = div;
	arr[4] = mod;
	if (str[0] == '+')
		ft_putnbr(arr[0](a, b));
	else if (str[0] == '-')
		ft_putnbr(arr[1](a, b));
	else if (str[0] == '*')
		ft_putnbr(arr[2](a, b));
	else if (str[0] == '/')
		ft_putnbr(arr[3](a, b));
	else if (str[0] == '%')
		ft_putnbr(arr[4](a, b));
	ft_putstr("\n");
}

int	check_operator(char *str)
{
	if (str[1] != '\0')
		return (0);
	if (str[0] == '+' || str[0] == '-' || str[0] == '*')
		return (1);
	else if (str[0] == '/' || str[0] == '%')
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;

	if (ac != 4)
		return (0);
	if (check_operator(av[2]) == 0)
	{
		ft_putstr("0\n");
		return (0);
	}
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (av[2][0] == '/' && b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	if (av[2][0] == '%' && b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	ft_calculator(a, av[2], b);
	return (0);
}
