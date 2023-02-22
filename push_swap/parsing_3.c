/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:52:26 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/07 15:52:28 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_arr(t_arr *arr, char **av)
{
	arr->before = NULL;
	arr->after = NULL;
	arr->res = NULL;
	arr->argv = av;
}

void	check_argv_int(char **av)
{
	long long	i;
	long long	j;
	long long	k;
	char		**tmp;

	i = 1;
	k = 0;
	while (av[i])
	{
		j = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[j])
		{
			if (ft_atoi(tmp[j]) > INT_MAX || ft_atoi(tmp[j]) < INT_MIN)
				print_error();
			j++;
			k++;
		}
		free_split(tmp);
		i++;
	}
}

long long	check_others(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '+')
		return (1);
	else if (c == '-')
		return (1);
	return (0);
}

void	check_argv_digit(char **av)
{
	long long	i;
	long long	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				if (!check_others(av[i][j]))
					print_error();
			}
			j++;
		}
		i++;
	}
}

void	check_double(t_arr *arr)
{
	long long	i;
	long long	j;

	i = 0;
	while (i < get_arr_size(arr->argv))
	{
		j = i + 1;
		while (j < get_arr_size(arr->argv))
		{
			if (arr->before[i] == arr->before[j])
				arr_error(arr);
			j++;
		}
		i++;
	}
}
