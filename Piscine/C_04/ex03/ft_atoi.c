/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:35:49 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/05 11:24:35 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_str(char *str, int *ptr)
{
	int	i;
	int	m_cnt;

	i = 0;
	m_cnt = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m_cnt *= -1;
		i++;
	}
	*ptr = i;
	return (m_cnt);
}

int	ft_atoi(char *str)
{
	int	i;
	int	m_cnt;
	int	res;

	i = 0;
	res = 0;
	m_cnt = check_str(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * res;
		res += (str[i] - '0');
		i++;
	}
	return (m_cnt * res);
}
