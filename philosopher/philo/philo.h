/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:19:34 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/06/27 16:05:28 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define LOCK 1
# define UNLOCK 2

typedef struct s_philo
{
	pthread_t	ph;
	long long	last_eat;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t fork_mtx;
	long long 		fork;
}	t_fork;

typedef struct s_philo_info
{
	t_philo			*philo_t;
	t_fork			*forks;

	struct timeval	start;
	long long		p_num;
	long long		die;
	long long		eat;
	long long		sleep;
	long long		eat_count;

	long long		idx; 

	pthread_mutex_t flag_mtx;
	long long		flag;

}	t_philo_info;


int	ft_atoi(const char *str);

// philo_set.c
t_philo_info	*set_info(int ac, char **av);
t_philo_info	*set_struct(t_philo_info *info);


// philo_free.c
t_philo_info	*free_atoi(t_philo_info *info);


#endif