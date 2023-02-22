/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:00:45 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 22:00:47 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	*make_arr(char **av)
{
	long long	size;
	long long	*arr;

	size = get_arr_size(av);
	arr = (long long *)malloc(sizeof(long long) * size);
	if (!arr)
		return (NULL);
	return (arr);
}

long long	*get_arr(t_arr *arr)
{
	long long	i;
	long long	j;
	long long	k;
	long long	*ar;
	char		**tmp;

	i = 1;
	k = 0;
	ar = make_arr(arr->argv);
	while (arr->argv[i])
	{
		j = 0;
		tmp = ft_split(arr->argv[i], ' ');
		while (tmp[j])
		{
			ar[k] = ft_atoi(tmp[j]);
			j++;
			k++;
		}
		free_split(tmp);
		i++;
	}
	return (ar);
}

void	sort_arr(t_arr *arr)
{
	long long	i;
	long long	j;
	long long	tmp;

	arr->after = get_arr(arr);
	i = 0;
	while (i < get_arr_size(arr->argv))
	{
		j = i + 1;
		while (j < get_arr_size(arr->argv))
		{
			if (arr->after[i] > arr->after[j])
			{
				tmp = arr->after[i];
				arr->after[i] = arr->after[j];
				arr->after[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	match_arr(t_arr *arr)
{
	long long	i;
	long long	j;

	arr->res = make_arr(arr->argv);
	i = 0;
	while (i < get_arr_size(arr->argv))
	{
		j = 0;
		while (j < get_arr_size(arr->argv))
		{
			if (arr->before[i] == arr->after[j])
				arr->res[i] = j + 1;
			j++;
		}
		i++;
	}
}

t_arr	*set_arr(char **av)
{
	t_arr		*arr;

	arr = (t_arr *)malloc(sizeof(t_arr));
	if (!arr)
		print_error();
	init_arr(arr, av);
	arr->before = get_arr(arr);
	check_double(arr);
	sort_arr(arr);
	match_arr(arr);
	return (arr);
}
