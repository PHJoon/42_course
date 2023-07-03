/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:19:34 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/07/03 17:02:50 by hyungjpa         ###   ########.fr       */
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

# define FORK	"has taken a fork\n"
# define EAT	"is eating\n"
# define SLEEP	"is sleeping\n"
# define THINK	"is thinking\n"
# define DIE	"died\n"

struct	s_ph;

typedef struct s_info {
	int				n_ph;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;

	int				die_flag;

	long			start_time;

	struct s_ph		*philos;

	pthread_mutex_t	print;
	pthread_mutex_t	die;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct s_ph {
	int				num;
	int				l_fork;
	int				r_fork;
	long			last_eat;

	struct s_info	*info;

	pthread_t		ph;
}	t_ph;


int	ft_atoi(const char *str);

// philo_set.c


// philo_free.c


#endif