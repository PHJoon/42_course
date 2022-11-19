/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:04:12 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/07 12:08:29 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_string(char c)
{
	if (c > 47 && c < 58)
		return (1);
	else if (c > 64 && c < 91)
		return (2);
	else if (c > 96 && c < 123)
		return (3);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{	
			if (ft_string(str[i]) == 3)
				str[i] -= 32;
		}
		else
		{
			if (ft_string(str[i]) == 2)
				str[i] += 32;
			if (ft_string(str[i - 1]) == 0 && ft_string(str[i]) == 3)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
