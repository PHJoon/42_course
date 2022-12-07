/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:28:40 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/12/05 15:47:34 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_hex_size_1(unsigned long long p)
{
	int	size;

	size = 0;
	if (p == 0)
		return (1);
	while (p != 0)
	{
		p /= 16;
		size++;
	}
	return (size);
}

static int	get_hex_size_2(unsigned int x)
{
	int	size;

	size = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 16;
		size++;
	}
	return (size);
}

int	ft_put_p(unsigned long long p)
{
	char	*s;
	int		hex_size;
	int		s_int;	

	hex_size = get_hex_size_1(p);
	s = (char *)malloc(sizeof(char) * (hex_size + 3));
	if (!s)
		return (-1);
	s[0] = '0';
	s[1] = 'x';
	s[hex_size + 2] = '\0';
	while (hex_size > 0)
	{
		s[hex_size + 1] = "0123456789abcdef"[p % 16];
		p /= 16;
		hex_size--;
	}
	s_int = ft_put_s(s);
	free(s);
	s = NULL;
	return (s_int);
}

int	ft_put_x(unsigned int x)
{
	char	*s;
	int		hex_size;
	int		s_int;	

	hex_size = get_hex_size_2(x);
	s = (char *)malloc(sizeof(char) * (hex_size + 1));
	if (!s)
		return (-1);
	s[hex_size] = '\0';
	hex_size--;
	while (hex_size >= 0)
	{
		s[hex_size] = "0123456789abcdef"[x % 16];
		x /= 16;
		hex_size--;
	}
	s_int = ft_put_s(s);
	free(s);
	s = NULL;
	return (s_int);
}

int	ft_put_xx(unsigned int xx)
{
	char	*s;
	int		hex_size;
	int		s_int;	

	hex_size = get_hex_size_2(xx);
	s = (char *)malloc(sizeof(char) * (hex_size + 1));
	if (!s)
		return (-1);
	s[hex_size] = '\0';
	hex_size--;
	while (hex_size >= 0)
	{
		s[hex_size] = "0123456789ABCDEF"[xx % 16];
		xx /= 16;
		hex_size--;
	}
	s_int = ft_put_s(s);
	free(s);
	s = NULL;
	return (s_int);
}
