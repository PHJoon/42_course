/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:35:59 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/04 22:36:21 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(long long v)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->val = v;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

t_stack	*init_stack(long long size)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->len = 0;
	s->max_len = size;
	s->head = NULL;
	s->tail = NULL;
	s->ss = 0;
	s->rr = 0;
	s->rrr = 0;
	return (s);
}

long long	min_num(t_stack *s)
{
	long long	res;
	t_node		*tmp;

	res = INT_MAX;
	tmp = s->head;
	while (tmp)
	{
		if (tmp->val < res)
			res = tmp->val;
		tmp = tmp->next;
	}
	return (res);
}

long long	check_sort(t_stack *s)
{
	t_node	*tmp;

	tmp = s->head;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->val > tmp->next->val)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*make_stack_a(t_stack *a, long long *arr, long long size)
{
	long long	i;

	i = 0;
	a->head = new_node(arr[i]);
	if (!a->head)
		return (NULL);
	a->tail = a->head;
	a->len++;
	i++;
	while (i < size)
	{
		a = add_back(a, arr[i]);
		if (!a)
			return (NULL);
		i++;
	}
	return (a);
}
