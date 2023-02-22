/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:18:23 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/03 09:18:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_stack *b)
{
	long long	tmp;

	if (a->len > 1)
	{
		tmp = a->head->val;
		a = del_front(a);
		a = add_back(a, tmp);
		if (!a)
			stack_error(a, b);
	}
	if (a->rr == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack *a, t_stack *b)
{
	long long	tmp;

	if (b->len > 1)
	{
		tmp = b->head->val;
		b = del_front(b);
		b = add_back(b, tmp);
		if (!b)
			stack_error(a, b);
	}
	if (b->rr == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	a->rr++;
	b->rr++;
	ra(a, b);
	rb(a, b);
	write(1, "rr\n", 3);
	a->rr--;
	b->rr--;
}
