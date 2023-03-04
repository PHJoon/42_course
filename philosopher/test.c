/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 05:07:48 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/05 05:07:49 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// void	*test(void *data)
// {
// 	int	i;
// 	int	a = *(int *)data;
// 	for (i = 0; i < 10; i++)
// 	{
// 		printf("%d\n", i * a);
// 	}
// 	return ((void *)(i * 100));
// }

// int main()
// {
// 	int a = 100;
// 	pthread_t thread_t;
// 	int	status;

// 	if (pthread_create(&thread_t, NULL, test, (void *)&a) < 0)
// 	{
// 		perror("thread create error: ");
// 		exit(0);
// 	}

// 	pthread_join(thread_t, (void **)&status);
// 	printf("Thread end %d\n", status);
// 	return 1;
// }

// ========================================
// ========================================

void	*thread_routine(void *arg)
{
	pthread_t	tid;

	tid = pthread_self();

	int i = 0;
	printf("\ttid:%x\n", tid);
	while (i < 10)
	{
		printf("\tnew thread:%d\n", i);
		i++;
		sleep(1);
	}
}

int main()
{
	pthread_t thread;

	pthread_create(&thread, NULL, thread_routine, NULL);

	int i = 0;
	printf("tid:%x\n", pthread_self());
	while (i < 5)
	{
		printf("main:%d\n", i);
		i++;
		sleep(1);
	}
}


// ========================================
// ========================================
// ========================================
// ========================================




