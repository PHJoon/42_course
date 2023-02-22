/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:00:36 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 22:00:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	split_len(char **tmp)
{
	long long	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

long long	get_arr_size(char **av)
{
	long long	i;
	long long	size;
	char		**tmp;

	i = 1;
	size = 0;
	while (av[i])
	{
		tmp = ft_split(av[i], ' ');
		size += split_len(tmp);
		free_split(tmp);
		i++;
	}
	return (size);
}

void	check_first_argv(char **av)
{
	long long	i;
	long long	flag;

	i = 0;
	flag = 0;
	while (av[1][i])
	{
		if (av[1][i] == '-')
			flag++;
		if (av[1][i] == '+')
			flag++;
		if (flag > 1)
			print_error();
		i++;
	}
}
