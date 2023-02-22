/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:59:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/03 09:59:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->head->val > a->tail->val)
		sa(a);
}

void	sort_three(t_stack *a, t_stack *b)
{
	if (a->head->val < a->head->next->val)
	{
		if (a->head->next->val > a->tail->val)
		{
			rra(a, b);
			if (a->head->val > a->head->next->val)
				sa(a);
		}
	}
	else
	{
		if (a->head->val < a->tail->val)
			sa(a);
		else
		{
			if (a->head->next->val < a->tail->val)
				ra(a, b);
			else
			{
				ra(a, b);
				sa(a);
			}
		}
	}
}
