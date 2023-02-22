/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:16:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/01 17:17:37 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	long long		val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	long long		len;
	long long		max_len;
	int				ss;
	int				rr;
	int				rrr;
}	t_stack;

typedef struct s_arr
{
	char		**argv;
	long long	*before;
	long long	*after;
	long long	*res;
}	t_arr;

void		print_error(void);
void		arr_error(t_arr *arr);
void		stack_error(t_stack *a, t_stack *b);
void		free_split(char **split);
void		free_arr(t_arr *arr);
void		free_stack(t_stack *s);
void		free_stack_all(t_stack *a, t_stack *b);
long long	ft_abs(long long x);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a, t_stack *b);
void		rb(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a, t_stack *b);
void		rrb(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);
long long	*make_arr(char **av);
long long	*get_arr(t_arr *arr);
void		sort_arr(t_arr *arr);
void		match_arr(t_arr *arr);
t_arr		*set_arr(char **av);
long long	split_len(char **tmp);
long long	get_arr_size(char **av);
void		init_arr(t_arr *arr, char **av);
void		check_first_argv(char **av);
void		check_argv_int(char **av);
long long	check_others(char c);
void		check_argv_digit(char **av);
void		check_double(t_arr *arr);
void		before_greedy(t_stack *a, t_stack *b);
void		start_greedy(t_stack *a, t_stack *b, long long *ra_c, \
long long *rb_c);
void		sort_stack(t_stack *a, t_stack *b);
long long	count_ra(t_stack *a);
void		check_b_to_a(t_stack *a, long long v, long long *ra_tmp);
long long	check_min_cnt(long long *min_cnt, \
long long ra_tmp, long long rb_tmp);
void		change_r_cnt(long long *ra_cnt, long long *rb_cnt, \
long long ra_tmp, long long rb_tmp);
void		find_best(t_stack *a, t_stack *b, long long *ra_cnt, \
long long *rb_cnt);
void		do_rr_rrr(t_stack *a, t_stack *b, long long *ra_cnt, \
long long *rb_cnt);
void		do_ra_rb(t_stack *a, t_stack *b, long long *ra_cnt, \
long long *rb_cnt);
void		end_a(t_stack *a, t_stack *b);
void		sort_two(t_stack *a);
void		sort_three(t_stack *a, t_stack *b);
t_node		*new_node(long long v);
t_stack		*init_stack(long long size);
long long	min_num(t_stack *s);
long long	check_sort(t_stack *s);
t_stack		*make_stack_a(t_stack *a, long long *arr, long long size);
t_stack		*add_back(t_stack *s, long long v);
t_stack		*add_front(t_stack *s, long long v);
t_stack		*del_back(t_stack *s);
t_stack		*del_front(t_stack *s);

#endif
