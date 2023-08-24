/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:17:21 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/24 12:10:38 by yoonslee         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	info;
	int		i;

	i = -1;
	if (argc != 5 && argc != 6)
	{
		printf("wrong argument number");
		return (1);
	}
	if (init_data(&info, argv) == ERROR)
		printf("error in initializing input\n");
	if (init_philo(&info) || init_mutex(&info))
		printf("error in initializing philo\n");
	if (create_philos(&info))
		printf("error in creating philo!\n");
	while (++i < info.p_numbers)
	{
		if (pthread_join(info.philo[i]->thread, NULL))
			return (1);
	}
	if (pthread_join(info.monitor, NULL))
		return (1);
	return (0);
}
