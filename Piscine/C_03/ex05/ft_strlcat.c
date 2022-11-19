/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 03:14:28 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/03 19:43:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;

	i = 0;
	d_len = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	if (d_len >= size)
		return (size + ft_strlen(src));
	else
	{
		while (i < size - 1 - d_len && src[i])
		{
			dest[d_len + i] = src[i];
			i++;
		}
		dest[d_len + i] = '\0';
		return (d_len + ft_strlen(src));
	}
}	
