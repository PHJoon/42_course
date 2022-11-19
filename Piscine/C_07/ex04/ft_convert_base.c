/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:05:47 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/11 12:30:41 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str);
int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);

int	cnt_nbr_base(int from_res, char *base)
{
	int	cnt;
	int	b_len;

	cnt = 0;
	b_len = ft_len(base);
	while (from_res != 0)
	{
		from_res /= b_len;
		cnt++;
	}
	return (cnt);
}

char	*ft_putnbr_base(int from_res, char *base, char *arr, int arr_len)
{
	int	b_len;
	int	m_flag;

	m_flag = 1;
	b_len = ft_len(base);
	if (from_res == 0)
	{
		arr[0] = base[0];
		arr[1] = '\0';
		return (arr);
	}
	arr[arr_len - 1] = '\0';
	arr_len--;
	if (from_res < 0)
	{
		arr[0] = '-';
		m_flag = -1;
	}
	while (from_res != 0)
	{
		arr[arr_len - 1] = base[m_flag * (from_res % b_len)];
		from_res /= b_len;
		arr_len--;
	}
	return (arr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*arr;
	int		from_res;
	int		arr_len;
	int		i;

	i = 0;
	arr_len = 0;
	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (0);
	from_res = ft_atoi_base(nbr, base_from);
	arr_len = cnt_nbr_base(from_res, base_to);
	if (from_res < 0)
		arr_len += 2;
	else if (from_res == 0)
		arr_len = 2;
	else
		arr_len += 1;
	arr = (char *)malloc(sizeof(char) * arr_len);
	if (!arr)
		return (0);
	return (ft_putnbr_base(from_res, base_to, arr, arr_len));
}
