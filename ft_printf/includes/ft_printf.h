/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:35:54 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/12/05 14:38:25 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_put_c(int c);
int	ft_put_s(char *s);
int	ft_put_d(int n);
int	ft_put_p(unsigned long long p);
int	ft_put_u(unsigned int u);
int	ft_put_x(unsigned int x);
int	ft_put_xx(unsigned int xx);
int	ft_printf(const char *s, ...);

#endif
