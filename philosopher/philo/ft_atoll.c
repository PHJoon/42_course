/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:56:35 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/07 13:33:49 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_str(char *str, int *ptr)
{
	int	i;
	int	m_cnt;

	i = 0;
	m_cnt = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m_cnt = -1;
		i++;
	}
	*ptr = i;
	return (m_cnt);
}

long long	ft_atoll(const char *str)
{
	int			i;
	int			m_cnt;
	long long	res;

	i = 0;
	res = 0;
	m_cnt = check_str((char *)str, &i);
	while (str[i] > 47 && str[i] < 58)
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * m_cnt);
}
