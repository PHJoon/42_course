/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:16:22 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/07 11:37:55 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_abs(long long x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

int	main(int ac, char **av)
{
	t_arr		*arr;
	t_stack		*a;
	t_stack		*b;

	if (ac == 1 || get_arr_size(av) == 0)
		exit(0);
	if (get_arr_size(av) > (INT_MAX - INT_MIN))
		print_error();
	check_first_argv(av);
	check_argv_digit(av);
	check_argv_int(av);
	arr = set_arr(av);
	a = init_stack(get_arr_size(av));
	b = init_stack(get_arr_size(av));
	a = make_stack_a(a, arr->res, get_arr_size(av));
	free_arr(arr);
	if (!a || !b)
	{
		free_stack_all(a, b);
		print_error();
	}
	sort_stack(a, b);
	free_stack_all(a, b);
	return (0);
}
