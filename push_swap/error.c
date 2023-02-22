/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:00:41 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/03 10:00:57 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	arr_error(t_arr *arr)
{
	free_arr(arr);
	print_error();
}

void	stack_error(t_stack *a, t_stack *b)
{
	free_stack_all(a, b);
	print_error();
}
