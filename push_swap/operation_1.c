/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:17:52 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/03 09:18:16 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	long long	tmp;

	if (a->len > 1)
	{
		tmp = a->head->val;
		a->head->val = a->head->next->val;
		a->head->next->val = tmp;
	}
	if (a->ss == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	long long	tmp;

	if (b->len > 1)
	{
		tmp = b->head->val;
		b->head->val = b->head->next->val;
		b->head->next->val = tmp;
	}
	if (b->ss == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	a->ss++;
	b->ss++;
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
	a->ss--;
	b->ss--;
}

void	pa(t_stack *a, t_stack *b)
{
	long long	tmp;

	if (b->len > 0)
	{
		tmp = b->head->val;
		b = del_front(b);
		if (a->len == 0)
		{
			a->head = new_node(tmp);
			a->tail = a->head;
			a->len++;
		}
		else
		{
			a = add_front(a, tmp);
			if (!a)
				stack_error(a, b);
		}
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	long long	tmp;

	if (a->len > 0)
	{
		tmp = a->head->val;
		a = del_front(a);
		if (b->len == 0)
		{
			b->head = new_node(tmp);
			b->tail = b->head;
			b->len++;
		}
		else
		{
			b = add_front(b, tmp);
			if (!b)
				stack_error(a, b);
		}
	}
	write(1, "pb\n", 3);
}
