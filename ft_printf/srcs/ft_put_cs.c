/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcsdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:12:27 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/12/05 14:38:01 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_put_c(int c)
{
	char	a;

	if (c == 0)
		return ((int)write(1, "", 1));
	a = (char)c;
	return ((int)write(1, &a, 1));
}

int	ft_put_s(char *s)
{
	if (s == 0)
		return ((int)write(1, "(null)", 6));
	if (ft_strlen(s) == 0)
		return (0);
	return ((int)write(1, s, ft_strlen(s)));
}
