/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonseonlee <yoonseonlee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:02:06 by yoonseonlee       #+#    #+#             */
/*   Updated: 2023/08/08 15:11:24 by yoonseonlee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_routine(t_data *info)
{
	int	i;
	
	gettimeofday(&info->start_time, NULL);
	i = -1;
	while (++i < info->p_numbers)
	{
		if (pthread_create(&info->philo[i]->p_id,
				NULL, &philo_fest, info->philo[i]))
		{
			printf("Error: create_threads: philo\n");
			return (THREAD_ERROR);
		}
	}
}

int	create_philos(t_data *info)
{
	int	i;

	pthread_mutex_lock(&info->monitoring);
	if (pthread_create(&info->monitor, NULL, &monitor_routine, info))
	{
		printf("Error: create_threads: monitor\n");
		return (THREAD_ERROR);
	}
	i = -1;
	while (++i < info->p_numbers)
		pthread_join(info->philo[i]->thread, NULL);
	pthread_mutex_unlock(&info->monitoring);
	return (SUCCESS);
}


