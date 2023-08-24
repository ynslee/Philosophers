/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:05:56 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/24 12:57:13 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error	philo_sleep(t_data *info, long long sleep)
{
	long long	wake_up;

	wake_up = timestamp(info->start_time) + sleep;
	while (timestamp(info->start_time) < wake_up)
	{
		if (philo_is_dead(info))
			return (ERROR);
		usleep(100);
	}
	return (SUCCESS);
}

t_error	philo_eating(t_data *info, long long eating)
{
	long long	full;

	full = timestamp(info->start_time) + eating;
	while (timestamp(info->start_time) < full)
	{
		if (philo_is_dead(info))
			return (ERROR);
		usleep(100);
	}
	return (SUCCESS);
}

t_error	get_ready_for_the_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->r_fork]);
	if (philo_print(philo, "has taken a fork") \
		|| philo->l_fork == philo->r_fork)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
		return (PRINT_ERROR);
	}
	pthread_mutex_lock(&philo->data->fork[philo->l_fork]);
	if (philo_print(philo, "has taken a fork") || philo->data->death == 1)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
		return (PRINT_ERROR);
	}
	return (SUCCESS);
}

t_error	dining(t_philo *philo)
{
	if (get_ready_for_the_meal(philo))
		return (ERROR);
	// if ((timestamp(philo->data->start_time) - philo->eaten_previous) \
	// 		>= philo->data->die_time)
	// {
	// 	philo->data->death = 1;
	// 	return (ERROR);
	// }
	if (philo_print(philo, "is eating"))
		return (ERROR);
	pthread_mutex_lock(&philo->meals_eaten_lock);
	// if (philo->data->death == 1)
	// {
	// 	pthread_mutex_unlock(&philo->meals_eaten_lock);
	// 	return (ERROR);
	// }
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->data->prepared_meals)
	{
		pthread_mutex_lock(&philo->data->finished);
		philo->is_finished = 1;
		pthread_mutex_unlock(&philo->data->finished);
		pthread_mutex_unlock(&philo->meals_eaten_lock);
		pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
		return (ATE_ALL);
	}
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	pthread_mutex_lock(&philo->time_lock);
	philo->eaten_previous = timestamp(philo->data->start_time);
	pthread_mutex_unlock(&philo->time_lock);
	if (philo_eating(philo->data, philo->data->eat_time))
	{
		pthread_mutex_unlock(&philo->meals_eaten_lock);
		pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
		pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
	return (SUCCESS);
}

t_error	sleeping(t_philo *philo)
{
	if (philo_print(philo, "is sleeping"))
		return (ERROR);
	philo_sleep(philo->data, philo->data->sleep_time);
	return (SUCCESS);
}

void	*philo_fest(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->meals_eaten_lock);
	philo->eaten_previous = gettimeofday(&philo->data->start_time, NULL);
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	// pthread_mutex_lock(&philo->data->monitoring);
	if (philo->p_id % 2 == 0)
	{
		if (sleeping(philo))
			return (NULL);
	}
	else if (philo->p_id % 2 == 1 && philo->p_id == philo->data->p_numbers && philo->p_id != 1)
	{
		if (sleeping(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
	}
	// pthread_mutex_unlock(&philo->data->monitoring);
	while (42)
	{
		if (dining(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (philo_print(philo, "is thinking"))
			break ;
		// if (philo->is_finished || philo->data->death == 1)
		// 	break ;
	}
	return (NULL);
}
