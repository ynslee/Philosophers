/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:17:15 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/10 14:08:55 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error	philo_thread_create(t_data *info)
{
	int	i;

	i = -1;
	while (++i < info->p_numbers)
	{
		printf("thread created\n");
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

	// pthread_mutex_lock(&info->monitoring);
	if (philo_thread_create(info) != SUCCESS)
		return (THREAD_ERROR);
	if (pthread_create(&info->monitor, NULL, &host_tasks, info))
	{
		printf("Error: create_threads: monitor\n");
		return (THREAD_ERROR);
	}
	// pthread_mutex_unlock(&info->monitoring);
	i = -1;
	return (SUCCESS);
}

