/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:27:05 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/07 22:42:57 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	**ft_split(char *str, char *charset);

int	main(int argc, char **argv)
{
	char	*str;
	char	*charset;
	char	**tab;
	int		i;

	if (argc != 3)
		printf("put two stings");
	str = argv[1];
	charset = argv[2];
	tab = ft_split(str, charset);
	i = 0;
	while (tab[i])
	{
		printf("i is %d->%s\n", i, tab[i]);
		i++;
	}
	return (0);
}
