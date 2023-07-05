/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:02:11 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/05 17:13:55 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_state(t_ph *philo, char *str)
{
	long	now;

	now = get_time() - philo->info->start_time;

	pthread_mutex_lock(&philo->info->die);
	pthread_mutex_lock(&philo->info->print);


	if (!philo->info->die_flag)
	{
		printf("%ld %d %s", now, philo->name, str);
		if (!ft_strncmp(str, DIE, 5))
		{
			philo->info->die_flag = 1;
			return (0);
		}
	}
	else
		return (0);

	pthread_mutex_unlock(&philo->info->die);
	pthread_mutex_unlock(&philo->info->print);
	return (1);
}
