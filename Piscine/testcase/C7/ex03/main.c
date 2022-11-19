/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:25:49 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/07 22:09:39 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	int		size;
	char	**strs;
	char	*sep;
	int		i;
	char	*result;

	if (argc < 3)
		printf("put more than one string");
	size = argc - 2;
	sep = argv[argc - 1];
	strs = (char **)malloc(size * sizeof(char *));
	if (!strs)
		return (0);
	i = -1;
	while (++i < size)
	{	
		strs[i] = argv[i + 1];
	}
	result = ft_strjoin(size, strs, sep);
	printf("%s\n", result);
}
