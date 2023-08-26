/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:17:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/26 12:57:46 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief 1 if any of philos havae died,
 * 0 if everyone is alive 
 */
static int	philo_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_eaten_lock);
	if ((timestamp(philo->data->start_time) - philo->eaten_previous) \
			>= philo->data->die_time)
	{
		pthread_mutex_unlock(&philo->meals_eaten_lock);
		philo_print(philo, "died");
		pthread_mutex_lock(&philo->data->monitoring);
		philo->data->death = 1;
		pthread_mutex_unlock(&philo->data->monitoring);
		return (1);
	}
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	return (0);
}

/**
* @brief 1 if philosopher is fully fed,
0 if no meals_to_be_eaten or not fully fed*/
static int	full_philo(t_data *info, t_philo *philo)
{
	if (info->prepared_meals == -1)
		return (0);
	pthread_mutex_lock(&philo->meals_eaten_lock);
	if (philo->is_finished == 1)
	{
		info->full_philo++;
		pthread_mutex_unlock(&philo->meals_eaten_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	return (0);
}

/**
 * @brief check if there is any death happening.
 *if it happens, make everyone unlock their mutexes and return.
 *Or if the eaing has been finished, also return
 * 
*/
void	*host_tasks(void *data)
{
	t_data	*info;
	int		i;

	info = (t_data *)data;
	i = -1;
	while (42)
	{
		usleep(500);
		info->full_philo = 0;
		while (++i < info->p_numbers)
		{
			if (full_philo(info, info->philo[i]))
			{
				if (info->full_philo == info->p_numbers)
					return (NULL);
			}
			if (philo_died(info->philo[i]))
				return (NULL);
		}
		if (info->full_philo != info->p_numbers)
			i = -1;
		else
			return (NULL);
	}
	return (NULL);
}
