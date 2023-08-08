/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:41:47 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/08 13:00:53 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
* @brief nulls everything of philo, puts id of philo
from 1 onwards
* @param i id of philosopher = i + 1*/
static void	philo_memset(t_data *info, int i)
{
	memset(info->philo[i], 0, sizeof(t_philo));
	info->philo[i]->p_id = i + 1;
	info->philo[i]->data = info;
	info->philo[i]->meals_eaten = 0;
}

t_error	init_philo(t_data *info)
{
	int	i;

	i = -1;
	info->philo = malloc(sizeof(t_philo *) * info->p_numbers);
	if (!info->philo)
		return (MALLOC_ERROR);
	while (++i < info->p_numbers)
	{
		info->philo[i] = malloc(sizeof(t_philo) * 1);
		if (!info->philo[i])
			return (MALLOC_ERROR);
		philo_memset(info, i);
		if (info->philo[i]->p_id < info->p_numbers)
			info->philo[i]->r_fork = info->philo[i + 1]->l_fork;
		else
			info->philo[i]->r_fork = info->philo[0]->l_fork;
		if (pthread_mutex_init(&info->philo[i]->meals_eaten_lock, NULL) || \
		pthread_mutex_init(&info->philo[i]->l_fork, NULL) || \
		pthread_mutex_init(&info->philo[i]->r_fork, NULL))
			return (MUTEX_ERROR);
	}
	return (SUCCESS);
}

t_error	init_mutex(t_data *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->eating, NULL))
		return (MUTEX_ERROR);
	if (pthread_mutex_init(&info->print, NULL))
		return (MUTEX_ERROR);
	if (pthread_mutex_init(&info->finished, NULL))
		return (MUTEX_ERROR);
	return (SUCCESS);
}

