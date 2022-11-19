/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:18:12 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/11 12:48:21 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_slen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_char(char **strs, int size)
{
	int	tot_size;
	int	i;
	int	j;

	tot_size = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			tot_size++;
			j++;
		}
		i++;
	}
	return (tot_size);
}

char	*to_arr(char *n_arr, char **strs, char *sep, int tot_size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < tot_size)
	{
		j = 0;
		while (strs[i][j])
		{
			n_arr[k] = strs[i][j];
			k++;
			j++;
		}
		j = 0;
		while (sep[j] && k < tot_size)
		{
			n_arr[k] = sep[j];
			k++;
			j++;
		}
		i++;
	}
	return (n_arr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*n_arr;
	int		tot_size;

	if (size == 0)
	{
		n_arr = (char *)malloc(sizeof(char));
		if (!n_arr)
			return (0);
		n_arr[0] = '\0';
		return (n_arr);
	}	
	tot_size = count_char(strs, size) + (ft_slen(sep) * (size - 1));
	n_arr = (char *)malloc(sizeof(char) * (tot_size + 1));
	if (!n_arr)
		return (0);
	n_arr[tot_size] = '\0';
	n_arr = to_arr(n_arr, strs, sep, tot_size);
	return (n_arr);
}
