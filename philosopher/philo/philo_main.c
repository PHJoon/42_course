/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:18:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/06/27 17:24:20 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*do_loop(void *data)
{
	t_philo_info	*info;

	info = (t_philo_info *)data;
	// 포크 잡기
	long long fork_idx = info->idx % (info->p_num - 1);

	if (info->idx % 2 == 0)
	{
		
		pthread_mutex_lock(&(info->forks[fork_idx + 1].fork_mtx));
		info->forks[fork_idx].fork = (long long)info->idx;
		printf("%lld가 %lld번 포크 잡음\n", info->idx + 1, fork_idx + 1);
		pthread_mutex_lock(&(info->forks[fork_idx].fork_mtx));
		info->forks[fork_idx].fork = (long long)info->idx;
		printf("%lld가 %lld번 포크 잡음\n", info->idx + 1, fork_idx);
		printf("%lld가 밥먹음\n", info->idx + 1);
		printf("%d\n", gettimeofday(&info->start, NULL));
	}
	else
	{
		pthread_mutex_lock(&(info->forks[fork_idx].fork_mtx));
		info->forks[fork_idx].fork = (long long)info->idx;
		printf("%lld가 %lld번 포크 잡음\n", info->idx + 1, fork_idx);
		pthread_mutex_lock(&(info->forks[fork_idx + 1].fork_mtx));
		info->forks[fork_idx].fork = (long long)info->idx;
		printf("%lld가 %lld번 포크 잡음\n", info->idx + 1, fork_idx + 1);
		printf("%lld가 밥먹음\n", info->idx + 1);
		printf("%d\n", gettimeofday(&info->start, NULL));
	}
	
	
	
	
	// 밥 먹기
	
	// 포크 내려놓기



	pthread_mutex_unlock(&(info->forks[fork_idx].fork_mtx));
	pthread_mutex_unlock(&(info->forks[fork_idx + 1].fork_mtx));

	// 
	return NULL;
}



int	start_philo(t_philo_info *info)
{
	long long	i;

	i = 0;
	while (i < info->p_num)
	{
		// printf("%lld 시작\n", i);
		info->idx = i;
		pthread_create(&info->philo_t[i].ph, NULL, do_loop, (void *)info);
		usleep(5);
		i++;
	}

	return (1);
}


int	main(int ac, char **av)
{
	t_philo_info	*info;

	if (!(ac == 5 || ac == 6))
		return (1);
	info = set_info(ac, av);
	if (!info)
		return (1);
	printf("%lld %lld %lld\n", info->p_num, info->die, info->eat);
	start_philo(info);


	
	return (0);
}
