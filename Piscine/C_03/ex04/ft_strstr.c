/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 02:56:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/03 14:05:51 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		ptr = &str[i];
		j = 0;
		while (to_find[j])
		{
			if (str[i + j] != to_find[j])
				break ;
			j++;
		}
		if (to_find[j] == '\0')
			return (ptr);
		else
			i++;
	}
	return (0);
}
