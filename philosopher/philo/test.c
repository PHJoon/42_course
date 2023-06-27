/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:12:33 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/23 15:16:34 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	mutex;
	pthread_t		p_thread[2];
	struct timeval	start;
	struct timeval	mytime;
}	t_philo;

int	ncnt = 0;

void	*do_loop(void *data)
{
	int		i;
	t_philo	*tmp;
	double	difftime;

	tmp = (t_philo *)data;
	pthread_mutex_lock(&(tmp->mutex));
	gettimeofday(&(tmp->mytime), NULL);
	difftime = (tmp->mytime.tv_sec - tmp->start.tv_sec) * 1000 + ((tmp->mytime.tv_usec - tmp->start.tv_usec) / 1000);
	printf("%f\n", difftime);
	for (i = 0; i < 10; i++)
	{
		printf("loop1 : %d\n", ncnt);
		ncnt++;
		if (i == 10)
			return (0);
		sleep(1);
	}
	pthread_mutex_unlock(&(tmp->mutex));
	return (0);
}

void	*do_loop2(void *data)
{
	int	i;
	t_philo	*tmp;
	double	difftime;

	tmp = (t_philo *)data;
	pthread_mutex_lock(&(tmp->mutex));
	gettimeofday(&(tmp->mytime), NULL);
	difftime = (tmp->mytime.tv_sec - tmp->start.tv_sec) * 1000 + ((tmp->mytime.tv_usec - tmp->start.tv_usec) / 1000);
	printf("%f\n", difftime);
	for (i = 0; i < 10; i++)
	{
		printf("loop2 : %d\n", ncnt);
		ncnt++;
		sleep(2);
	}
	pthread_mutex_unlock(&(tmp->mutex));
	return (NULL);
}

int	main()
{
	int	thr_id;
	int	status;
	int	a = 1;
	t_philo	philo;

	pthread_mutex_init(&(philo.mutex), NULL);
	gettimeofday(&(philo.start), NULL);
	thr_id = pthread_create(&(philo.p_thread[0]), NULL, do_loop, (void *)&philo);
	sleep(1);
	thr_id = pthread_create(&(philo.p_thread[1]), NULL, do_loop2, (void *)&philo);

	pthread_join(philo.p_thread[0], (void *)&status);
	pthread_join(philo.p_thread[1], (void *)&status);

	status = pthread_mutex_destroy(&(philo.mutex));
	printf("code = %d\n", status);
	printf("programming is end\n");
	return 0;
}