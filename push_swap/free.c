/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:12:05 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/02/07 16:12:07 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	long long	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_arr(t_arr *arr)
{
	if (arr->before != NULL)
		free(arr->before);
	if (arr->before != NULL)
		free(arr->after);
	if (arr->res != NULL)
		free(arr->res);
	free(arr);
}

void	free_stack(t_stack *s)
{
	if (s == NULL)
		return ;
	while (s->len > 0)
		del_front(s);
	free(s);
}

void	free_stack_all(t_stack *a, t_stack *b)
{
	if (a == NULL)
		free_stack(b);
	else if (b == NULL)
		free_stack(a);
	else
	{	
		free_stack(a);
		free_stack(b);
	}
}
