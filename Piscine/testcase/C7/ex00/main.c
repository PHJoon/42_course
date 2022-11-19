/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:22:36 by yoonsele          #+#    #+#             */
/*   Updated: 2022/09/07 21:59:31 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*a;
	char	*b;

	a = "happy";
	b = "happy";
	strdup(a);
	ft_strdup(b);
	printf("%s\n", a);
	printf("%s\n", b);
}
