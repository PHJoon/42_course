/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:05:35 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/07 09:06:01 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	count_ra(t_stack *a)
{
	long long	ra_cnt;
	long long	min_a;
	t_node		*tmp_head;

	ra_cnt = 0;
	min_a = min_num(a);
	tmp_head = a->head;
	while (tmp_head)
	{
		if (tmp_head->val == min_a)
			break ;
		tmp_head = tmp_head->next;
		ra_cnt++;
	}
	if (ra_cnt > a->len / 2)
		ra_cnt -= a->len;
	return (ra_cnt);
}

void	check_b_to_a(t_stack *a, long long v, long long *ra_tmp)
{
	long long	tmp_tail_val;
	long long	min_a;
	t_node		*tmp_head;

	tmp_head = a->head;
	tmp_tail_val = a->tail->val;
	min_a = min_num(a);
	while (tmp_head)
	{
		if (tmp_head->val > v && tmp_tail_val < v)
			break ;
		if ((tmp_head->val < v && tmp_tail_val < v) || \
		(tmp_head->val > v && tmp_tail_val > v))
		{
			if (tmp_head->val == min_a)
				break ;
		}
		*ra_tmp += 1;
		tmp_tail_val = tmp_head->val;
		tmp_head = tmp_head->next;
	}
	if (*ra_tmp > a->len / 2)
		*ra_tmp -= a->len;
}

long long	check_min_cnt(long long *min_cnt, \
long long ra_tmp, long long rb_tmp)
{
	long long	tmp;

	tmp = 0;
	if (ra_tmp * rb_tmp > 0)
		tmp = ft_abs(ft_abs(ra_tmp) - ft_abs(rb_tmp));
	if (*min_cnt > ft_abs(ra_tmp) + ft_abs(rb_tmp))
	{
		*min_cnt = ft_abs(ra_tmp) + ft_abs(rb_tmp) - tmp;
		return (1);
	}
	return (0);
}

void	change_r_cnt(long long *ra_cnt, long long *rb_cnt, \
long long ra_tmp, long long rb_tmp)
{
	*ra_cnt = ra_tmp;
	*rb_cnt = rb_tmp;
}

void	find_best(t_stack *a, t_stack *b, long long *ra_cnt, long long *rb_cnt)
{
	long long	min_cnt;
	long long	ra_tmp;
	long long	rb_tmp;
	long long	rb_tmp_tmp;
	t_node		*tmp;

	rb_tmp = 0;
	min_cnt = a->max_len * 2;
	tmp = b->head;
	while (tmp)
	{
		ra_tmp = 0;
		check_b_to_a(a, tmp->val, &ra_tmp);
		if (rb_tmp > b->len / 2)
			rb_tmp_tmp = rb_tmp - b->len;
		else
			rb_tmp_tmp = rb_tmp;
		if (check_min_cnt(&min_cnt, ra_tmp, rb_tmp_tmp))
			change_r_cnt(ra_cnt, rb_cnt, ra_tmp, rb_tmp_tmp);
		tmp = tmp->next;
		rb_tmp++;
	}
}
