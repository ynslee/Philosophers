/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:17:21 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/08 14:21:41 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// memset, printf, malloc, free, write, usleep, gettimeofday, 
// pthread_create, pthread_join, pthread_detach,
// pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock
// These are the allowed function.
// ./philo [number of philo][time to die][time to eat][time to sleep][number of times to eat]

int	create_philos(t_data *info)
{
	int	i;

	gettimeofday(&info->start_time, NULL);
	i = 0;
	while (i < info->p_numbers)
	{
		if (pthread_create(&info->philo[i]->p_id,
				NULL, &philo_fest, info->philo[i]))
		{
			printf("Error: create_threads: philo\n");
			return (THREAD_ERROR);
		}
		i++;
	}
	if (pthread_create(&info->monitor, NULL, &monitor_routine, info))
	{
		printf("Error: create_threads: monitor\n");
		return (THREAD_ERROR);
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc != 5 && argc != 6)
	{
		printf("wrong argument number");
		return (1);
	}
	if (init_data(&info, argv) == FAIL)
		printf("error in initializing input\n");
	if (init_philo(&info) || init_mutex(&info))
		printf("error in initializing philo\n");
	if (create_philos(&info))
	// 	error("error when creating philos!\n");
}
