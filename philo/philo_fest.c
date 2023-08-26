/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:05:56 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/26 12:38:18 by yoonslee         ###   ########.fr       */
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
	if (philo_print(philo, "has taken a fork"))
	{
		drop_the_fork(philo);
		return (PRINT_ERROR);
	}
	return (SUCCESS);
}

t_error	dining(t_philo *philo)
{
	if (get_ready_for_the_meal(philo))
		return (ERROR);
	if (philo_print(philo, "is eating"))
		return (ERROR);
	pthread_mutex_lock(&philo->meals_eaten_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	if (philo->meals_eaten == philo->data->prepared_meals)
	{
		pthread_mutex_lock(&philo->meals_eaten_lock);
		philo->is_finished = 1;
		pthread_mutex_unlock(&philo->meals_eaten_lock);
		drop_the_fork(philo);
		return (ATE_ALL);
	}
	if (philo_eating(philo->data, philo->data->eat_time))
	{
		drop_the_fork(philo);
		return (ERROR);
	}
	pthread_mutex_lock(&philo->meals_eaten_lock);
	philo->eaten_previous = timestamp(philo->data->start_time);
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	drop_the_fork(philo);
	return (SUCCESS);
}

void	*philo_fest(void *data)
{
	t_philo			*philo;

	philo = (t_philo *)data;
	gettimeofday(&philo->data->start_time, NULL);
	pthread_mutex_lock(&philo->data->monitoring);
	pthread_mutex_unlock(&philo->data->monitoring);
	if (philo->p_id % 2 == 0)
	{
		sleeping(philo);
	}
	while (42)
	{
		if (dining(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (philo_print(philo, "is thinking"))
			break ;
	}
	return (NULL);
}
