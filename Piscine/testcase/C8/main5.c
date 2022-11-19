/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:33:09 by hyungjpa          #+#    #+#             */
/*   Updated: 2022/09/11 13:17:18 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int	main(int ac, char **av)
{
	t_stock_str	*arr;
	char	**x;
	int	i;
	int	j;

	i = 1;
	j = 0;
	x = (char **)malloc(sizeof(char *) * ac);
	while (i < ac)
	{
		x[j] = av[i];
		i++;
		j++;
	}
	arr = ft_strs_to_tab(ac - 1, x);
	ft_show_tab(arr);
}
