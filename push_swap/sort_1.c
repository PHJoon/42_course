/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:59:21 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/07 08:59:44 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	before_greedy(t_stack *a, t_stack *b)
{
	long long	pivot_1;
	long long	pivot_2;

	pivot_1 = a->len / 3 * 2;
	pivot_2 = a->len / 3;
	while (a->len > pivot_2)
	{
		if (a->head->val > pivot_1)
			ra(a, b);
		else
		{
			pb(a, b);
			if (b->head->val < pivot_2)
				rb(a, b);
		}
		if (a->len < 4 || b->len == pivot_1)
			break ;
	}
	while (a->len > 3)
		pb(a, b);
	sort_three(a, b);
}

void	start_greedy(t_stack *a, t_stack *b, long long *ra_c, long long *rb_c)
{
	if (b->len == 1)
	{
		check_b_to_a(a, b->head->val, ra_c);
		*rb_c = 0;
	}
	else
		find_best(a, b, ra_c, rb_c);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	long long	ra_cnt;
	long long	rb_cnt;

	ra_cnt = 0;
	rb_cnt = 0;
	if (a->len == 3)
		sort_three(a, b);
	else if (a->len == 2)
		sort_two(a);
	else if (a->len == 1 || check_sort(a))
		return ;
	else
	{
		before_greedy(a, b);
		while (b->len > 0)
		{
			start_greedy(a, b, &ra_cnt, &rb_cnt);
			do_rr_rrr(a, b, &ra_cnt, &rb_cnt);
			do_ra_rb(a, b, &ra_cnt, &rb_cnt);
			pa(a, b);
		}
		end_a(a, b);
	}
}
