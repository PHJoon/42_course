/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:41:58 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/05 08:53:32 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_len(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 32)
			return (0);
		if (base[i] >= 9 && base[i] <= 13)
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

int	inbase(char x, char	*base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_idx_atoi(char *str, int *ptr)
{
	int	i;
	int	m_cnt;

	i = 0;
	m_cnt = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m_cnt *= -1;
		i++;
	}
	*ptr = i;
	return (m_cnt);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b_len;
	int	m_cnt;
	int	res;
	int	i;

	b_len = ft_len(base);
	res = 0;
	i = 0;
	if (check_base(base) == 0)
		return (0);
	m_cnt = ft_idx_atoi(str, &i);
	while (inbase(str[i], base) >= 0)
	{
		res = res * b_len;
		res += inbase(str[i], base);
		i++;
	}
	return (m_cnt * res);
}
