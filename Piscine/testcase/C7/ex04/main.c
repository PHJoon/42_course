/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:26:41 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/07 18:47:21 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int argc, char **argv)
{
	char	*nbr;
	char	*base_from;
	char	*base_to;
	char	*result;

	if (argc != 4)
		printf("put three stings");
	nbr = argv[1];
	base_from = argv[2];
	base_to = argv[3];
	result = ft_convert_base(nbr, base_from, base_to);
	printf("%s\n", result);
	return (0);
}
