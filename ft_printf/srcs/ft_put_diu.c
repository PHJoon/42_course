/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:26:03 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/12/05 12:26:08 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_size(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*do_uitoa(char *arr, unsigned int n, int size)
{
	arr[size] = '\0';
	size--;
	if (n == 0)
	{
		arr[size] = '0';
		return (arr);
	}
	while (n != 0)
	{
		arr[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (arr);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*arr;
	int		size;

	size = get_size(n);
	if (n == 0)
		size++;
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (0);
	arr = do_uitoa(arr, n, size);
	return (arr);
}

int	ft_put_d(int n)
{
	char	*s;
	int		s_int;

	s = ft_itoa(n);
	if (s == 0)
		return (-1);
	s_int = ft_put_s(s);
	free(s);
	s = NULL;
	return (s_int);
}

int	ft_put_u(unsigned int u)
{
	char	*s;
	int		s_int;

	s = ft_uitoa(u);
	if (s == 0)
		return (-1);
	s_int = ft_put_s(s);
	free(s);
	s = NULL;
	return (s_int);
}
