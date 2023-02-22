/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:08:07 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/07 09:08:23 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*add_back(t_stack *s, long long v)
{
	t_node	*new;

	new = new_node(v);
	if (!new)
		return (NULL);
	s->tail->next = new;
	new->prev = s->tail;
	s->tail = new;
	s->len++;
	return (s);
}

t_stack	*add_front(t_stack *s, long long v)
{
	t_node	*new;

	new = new_node(v);
	if (!new)
		return (NULL);
	s->head->prev = new;
	new->next = s->head;
	s->head = new;
	s->len++;
	return (s);
}

t_stack	*del_back(t_stack *s)
{
	t_node	*tmp;

	if (s->len == 0)
		return (s);
	if (s->len == 1)
	{
		free(s->head);
		s->len--;
		return (s);
	}
	tmp = s->tail->prev;
	free(s->tail);
	tmp->next = NULL;
	s->tail = tmp;
	s->len--;
	return (s);
}

t_stack	*del_front(t_stack *s)
{
	t_node	*tmp;

	if (s->len == 0)
		return (s);
	if (s->len == 1)
	{
		free(s->head);
		s->len--;
		return (s);
	}
	tmp = s->head->next;
	free(s->head);
	tmp->prev = NULL;
	s->head = tmp;
	s->len--;
	return (s);
}
