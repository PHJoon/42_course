/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:48:40 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/03 09:49:00 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, t_stack *b)
{
	long long	tmp;

	if (a->len > 1)
	{
		tmp = a->tail->val;
		a = del_back(a);
		a = add_front(a, tmp);
		if (!a)
			stack_error(a, b);
	}
	if (a->rrr == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *a, t_stack *b)
{
	long long	tmp;

	if (b->len > 1)
	{
		tmp = b->tail->val;
		b = del_back(b);
		b = add_front(b, tmp);
		if (!b)
			stack_error(a, b);
	}
	if (b->rrr == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	a->rrr++;
	b->rrr++;
	rra(a, b);
	rrb(a, b);
	write(1, "rrr\n", 4);
	a->rrr--;
	b->rrr--;
}
