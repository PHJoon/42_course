/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:40:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/07 13:42:49 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_int(long long i)
{
	if (i <= 0 || i > 2147483647)
		return (0);
	return (1);
}

int	check_argv(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (0);
	if (!check_int(ft_atoll(av[1])) || !check_int(ft_atoll(av[2])) \
	|| !check_int(ft_atoll(av[3])) || !check_int(ft_atoll(av[4])))
		return (0);
	if (ac == 6 && !check_int(ft_atoll(av[5])))
		return (0);
	return (1);
}
