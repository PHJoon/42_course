/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:47:16 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/07 21:33:17 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first_part(unsigned long long x)
{	
	int	box[16];
	int	i;

	i = 15;
	while (i >= 0)
	{
		box[i] = (x % 16) + '0';
		x = x / 16;
		i--;
	}
	while (i < 16)
	{
		write(1, &"0123456789abcdef"[(box[i] - '0')], 1);
		i++;
	}
	write(1, ": ", 2);
}

void	ft_second_part(unsigned char *str, unsigned int len)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 0;
	while (i < len)
	{
		write(1, &"0123456789abcdef"[(str[i] / 16)], 1);
		write(1, &"0123456789abcdef"[(str[i] % 16)], 1);
		size += 2;
		if (i % 2 == 1)
		{
			write(1, " ", 1);
			size += 1;
		}
		i++;
	}
	while (size < 40)
	{
		write(1, " ", 1);
		size++;
	}
}

void	ft_printable(unsigned char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] < 32 || str[i] > 126)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	unsigned char	len;
	unsigned int	i;

	i = 0;
	while (size > 0)
	{
		if (size > 16)
			len = 16;
		else
			len = size;
		str = addr + i * 16;
		ft_first_part(((unsigned long long)addr) + (i * 16));
		ft_second_part(str, len);
		ft_printable(str, len);
		write(1, "\n", 1);
		i++;
		size -= len;
	}
	return (addr);
}
