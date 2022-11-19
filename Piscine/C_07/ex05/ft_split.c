/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:30:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/11 12:06:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	arr_size(char *str, char *charset)
{
	int	arr_size;
	int	i;
	int	j;

	arr_size = 0;
	i = 0;
	while (str[i])
	{
		if (check_set(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && check_set(str[i + j], charset) == 0)
				j++;
			arr_size++;
			i += j;
		}
	}
	return (arr_size);
}

char	**split(char **arr, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (check_set(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && check_set(str[i + j], charset) == 0)
				j++;
			arr[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (!arr[k])
				return (0);
			ft_strncpy(arr[k++], &str[i], j);
			i += j;
		}
	}
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		size;

	size = arr_size(str, charset);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (0);
	arr[size] = 0;
	arr = split(arr, str, charset);
	return (arr);
}
