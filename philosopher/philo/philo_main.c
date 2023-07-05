/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:18:55 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/05 13:57:20 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}


int	check_av(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (0);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 \
	|| ft_atoi(av[4]) <= 0)
		return (0);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (0);
	return (1);
}

t_info	*set_info(int ac, char **av)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->n_ph = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->max_eat = -1;
	if (ac == 6)
		info->max_eat = ft_atoi(av[5]);
	
	if (pthread_mutex_init(&info->print, NULL) == -1)
	{
		free(info);
		return (NULL);
	}
	if (pthread_mutex_init(&info->die, NULL) == -1)
	{
		free(info);
		pthread_mutex_destroy(&info->print);
		return (NULL);
	}

	if (pthread_mutex_init(&info->time_mtx, NULL) == -1)
	{
		// free
		return (NULL);
	}

	
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->n_ph);
	int	i;
	i = -1;
	while (++i < info->n_ph)
		pthread_mutex_init(&info->forks[i], NULL);
		// 뮤텍스 init 실패 로직 추가
	return (info);
}

t_ph	*set_ph(t_info *info)
{
	t_ph	*philos;

	philos = (t_ph *)malloc(sizeof(t_ph) * info->n_ph);
	if (!philos)
		return (NULL);
	int i;
	i = -1;
	while (++i < info->n_ph)
	{
		philos[i].name = i + 1;
		philos[i].eat_num = 0;
		philos[i].last_eat = 0;
		philos[i].fork_one = (i + 1) % (info->n_ph + 1);
		philos[i].fork_two = i;
		if (i % 2 == 1)
		{
			philos[i].fork_one = i;
			philos[i].fork_two = (i + 1) % (info->n_ph + 1);
		}
		philos[i].info = info;
	}
	info->philos = philos;
	return (philos);
}

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
			philo->info->die_flag = 1;
	}
	else
		return (0);

	pthread_mutex_unlock(&philo->info->die);
	pthread_mutex_unlock(&philo->info->print);
	return (1);
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


void	*philo_loop(void *data)
{
	t_ph	*philo;

	// 세팅
	philo = (t_ph *)data;
	philo->last_eat = philo->info->start_time;

	// 시간 설정되면 루프 돌아가는 뮤텍스
	int	time_flag;

	time_flag = 1;
	if (time_flag)
	{
		pthread_mutex_lock(&philo->info->time_mtx);
		time_flag = 0;
		philo->last_eat = philo->info->start_time;
		pthread_mutex_unlock(&philo->info->time_mtx);
	}

	//먹고
	
	pthread_mutex_lock(&philo->info->forks[philo->fork_one]);
	if (!print_state(philo, FORK))
		return (NULL);
	pthread_mutex_lock(&philo->info->forks[philo->fork_two]);
	if (!print_state(philo, FORK))
		return (NULL);

	if (!print_state(philo, EAT))
		return (NULL);

	philo->eat_num++;
	philo->last_eat = get_time();

	if (philo->info->max_eat != -1 && philo->eat_num == philo->info->max_eat)
		return (NULL);

	do_time(philo->info->t_eat, philo->info);

	pthread_mutex_unlock(&philo->info->forks[philo->fork_one]);
	pthread_mutex_unlock(&philo->info->forks[philo->fork_two]);

	//자고
	if (!print_state(philo, SLEEP))
		return (NULL);
	do_time(philo->info->t_sleep, philo->info);

	//생각하고
	if (!print_state(philo, THINK))
		return (NULL);

	return (NULL);
}

int	check_dead_loop(t_ph *philos, t_info *info)
{
	int			i;
	long long	now;

	i = -1;
	usleep(2000);
	while (++i < info->n_ph)
	{
		now = get_time();
		if (now - philos[i].last_eat > info->t_eat || info->finish_meal == info->n_ph)
		{
			print_state(&philos[i], DIE);
			return (0);
		}
	}

	return (1);
}





int	start_philo(t_ph *philos, t_info *info)
{
	int	i;

		
	i = -1;

	// 시간 뮤텍스
	pthread_mutex_lock(&info->time_mtx);
	
	while (++i < info->n_ph)
	{
		pthread_create(&philos[i].ph, NULL, philo_loop, (void *)&philos[i]);
		if (i % 2 == 1)
			usleep(100);
		// pthread_create 실패 로직 추가
	}
	info->start_time = get_time();
	// 시간 뮤텍스 언락
	pthread_mutex_unlock(&info->time_mtx);

	// 메인스레드가 죽음 체크
	check_dead_loop(philos, info);

	i = -1;
	while (++i < info->n_ph)
	{
		pthread_join(philos[i].ph, NULL);
	}
	// mutex destroy

	return (1);
}




int	main(int ac, char **av)
{
	t_info	*info;
	t_ph	*philos;

	if (!check_av(ac, av))
		return (1);

	info = set_info(ac, av);
	if (!info)
		return (1);

	philos = set_ph(info);
	if (!philos)
		return (1);

	start_philo(philos, info);

	// free 구조체

	return (0);
}
