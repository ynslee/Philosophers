/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:17:15 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/26 12:35:39 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief check if dead flag is 1
 * 
 * @return returns 1, if death happened, 0 if everyone is alive.
 */
int	philo_is_dead(t_data *info)
{
	pthread_mutex_lock(&info->monitoring);
	if (info->death == 1)
	{
		pthread_mutex_unlock(&info->monitoring);
		return (1);
	}
	pthread_mutex_unlock(&info->monitoring);
	return (0);
}

t_error	philo_thread_create(t_data *info)
{
	int	i;

	i = -1;
	while (++i < info->p_numbers)
	{
		if (pthread_create(&info->philo[i]->thread,
				NULL, &philo_fest, info->philo[i]))
		{
			printf("Error: create_threads: philo\n");
			return (THREAD_ERROR);
		}
	}
	return (SUCCESS);
}

t_error	create_philos(t_data *info)
{
	int	i;

	if (philo_thread_create(info) != SUCCESS)
		return (THREAD_ERROR);
	if (pthread_create(&info->monitor, NULL, &host_tasks, info))
	{
		printf("Error: create_threads: monitor\n");
		return (THREAD_ERROR);
	}
	i = -1;
	return (SUCCESS);
}

