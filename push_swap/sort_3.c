/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:00:12 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/03 10:00:32 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr_rrr(t_stack *a, t_stack *b, long long *ra_cnt, long long *rb_cnt)
{
	while (*ra_cnt < 0 && *rb_cnt < 0)
	{
		rrr(a, b);
		(*ra_cnt)++;
		(*rb_cnt)++;
	}
	while (*ra_cnt > 0 && *rb_cnt > 0)
	{
		rr(a, b);
		(*ra_cnt)--;
		(*rb_cnt)--;
	}
}

void	do_ra_rb(t_stack *a, t_stack *b, long long *ra_cnt, long long *rb_cnt)
{
	while (*ra_cnt > 0)
	{
		ra(a, b);
		(*ra_cnt)--;
	}
	while (*ra_cnt < 0)
	{
		rra(a, b);
		(*ra_cnt)++;
	}
	while (*rb_cnt > 0)
	{
		rb(a, b);
		(*rb_cnt)--;
	}
	while (*rb_cnt < 0)
	{
		rrb(a, b);
		(*rb_cnt)++;
	}
}

void	end_a(t_stack *a, t_stack *b)
{
	long long	ra_cnt;

	ra_cnt = count_ra(a);
	while (ra_cnt < 0)
	{
		rra(a, b);
		ra_cnt++;
	}
	while (ra_cnt > 0)
	{
		ra(a, b);
		ra_cnt--;
	}
}
