/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:00:29 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/05 16:03:04 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	do_time(long long usleep_time, t_info *info)
{
	long long	start;

	start = get_time();
	while (!info->die_flag)
	{
		if (get_time() - start >= usleep_time)
			break ;
		usleep(100);
	}
}
