/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:19:31 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/11 15:29:58 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_abs.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", ABS(atoi(av[1])));
}
