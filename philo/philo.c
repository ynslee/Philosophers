/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:17:21 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/15 15:17:28 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// memset, prinft, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_join,
// pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock
// These are the allowed function.

int main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
	{
		return 1;
	}
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	{
		return 2;
	}
	if (pthread_join(t1, NULL) != 0)
	{
		return 3;
	}
	if (pthread_join(t2, NULL) != 0)
	{
		return 4;
	}
	pthread_mutex_destroy(&mutex);
	return 0;
}
