/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:55:19 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/12/07 08:29:34 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_con(va_list ap_cp, char a)
{
	if (a == 'c')
		return (ft_put_c(va_arg(ap_cp, int)));
	else if (a == 's')
		return (ft_put_s(va_arg(ap_cp, char *)));
	else if (a == 'p')
		return (ft_put_p(va_arg(ap_cp, unsigned long long)));
	else if (a == 'd' || a == 'i')
		return (ft_put_d(va_arg(ap_cp, int)));
	else if (a == 'u')
		return (ft_put_u(va_arg(ap_cp, unsigned int)));
	else if (a == 'x')
		return (ft_put_x(va_arg(ap_cp, unsigned int)));
	else if (a == 'X')
		return (ft_put_xx(va_arg(ap_cp, unsigned int)));
	else
		return (ft_put_c(a));
}

static int	do_printf(va_list ap_cp, const char *s)
{
	size_t	i;
	int		w_check;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1])
				w_check = check_con(ap_cp, s[i + 1]);
			i++;
		}
		else
			w_check = (int)write(1, &s[i], 1);
		if (w_check == -1)
			return (-1);
		cnt += w_check;
		i++;
	}
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	va_list	ap_cp;
	int		cnt;

	va_start(ap, s);
	va_copy(ap_cp, ap);
	cnt = do_printf(ap_cp, s);
	va_end(ap);
	va_end(ap_cp);
	return (cnt);
}
