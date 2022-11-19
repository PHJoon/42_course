/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:33:08 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/11 13:33:59 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*re;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	re = (char *)malloc(sizeof(char) * (len + 1));
	if (!re)
		return (0);
	while (src[i])
	{
		re[i] = src[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	i = 0;
	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (0);
	while (i < ac)
	{
		arr[i].size = len(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	arr[i].size = 0;
	arr[i].copy = 0;
	return (arr);
}
