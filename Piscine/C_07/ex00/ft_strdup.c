/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:18:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/10 11:15:55 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
