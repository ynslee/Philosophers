/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:38:46 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/29 12:07:13 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Frees all memory and destroys mutexes.
 * 
 * @param d the main data struct s_common_data.
 */
void	free_memory(t_common_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		pthread_mutex_destroy(&d->forks[i]);
		pthread_mutex_destroy(&d->philosophers[i]->eat_count_lock);
		pthread_mutex_destroy(&d->philosophers[i]->eat_finished_lock);
		pthread_mutex_destroy(&d->philosophers[i]->eat_timestamp_lock);
		if (d->philosophers[i])
			free(d->philosophers[i]);
		i++;
	}
	pthread_mutex_destroy(&d->stdout_lock);
	pthread_mutex_destroy(&d->is_finished_lock);
	if (d->philosophers)
		free(d->philosophers);
	if (d->forks)
		free(d->forks);
	free(d);
}

/**
 * @brief Initialises mutexes that are not handled by an individual thread,
 * meaning all mutexes in data and data->forks.
 * 
 * @param data the main data struct s_common_data.
 * @return t_err - 0 for success or an error code defined in t_err.
 */
t_err	init_mutexes(t_common_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->stdout_lock, NULL))
		return (MUTEX_FAIL);
	if (pthread_mutex_init(&data->is_finished_lock, NULL))
		return (MUTEX_FAIL);
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	if (!data->forks)
		return (MALLOC_FAIL);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (MUTEX_FAIL);
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Set the fork ids. Odd numbered philosophers get their left fork in
 * their fork[0] and right fork in fork[1], even numbered philos get the exact
 * opposite.
 * 
 * @param data the main data struct s_common_data.
 * @param philo_id id of the philosopher whose forks are being assigned.
 * @return t_err - 0 for success or an error code defined in t_err.
 */
t_err	set_fork_ids(t_common_data *data, int philo_id)
{
	if (!data || philo_id < 0)
		return (FAIL);
	data->philosophers[philo_id - 1]->fork_id[0] = philo_id - 1;
	data->philosophers[philo_id - 1]->fork_id[1] = philo_id;
	if (philo_id == data->number_of_philosophers)
		data->philosophers[philo_id - 1]->fork_id[1] = 0;
	return (SUCCESS);
}

/**
 * @brief Initialize the philosophers array 
 * and individual philosopher structs with their mallocs and mutexes.
 * 
 * @param data the main data struct s_common_data.
 * @return t_err - 0 for success or an error code defined in t_err.
 */
t_err	init_philosophers(t_common_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philosopher *)
			* data->number_of_philosophers);
	if (!data->philosophers)
		return (MALLOC_FAIL);
	i = 0;
	while (i++ < data->number_of_philosophers)
	{
		data->philosophers[i - 1] = malloc(sizeof(t_philosopher));
		if (!data->philosophers[i - 1])
			return (MALLOC_FAIL);
		init_philosophers_basic_values(data, i - 1);
		if (set_fork_ids(data, data->philosophers[i - 1]->philo_id) != SUCCESS)
			return (FAIL);
		if (pthread_mutex_init(&data->philosophers[i - 1]->eat_count_lock, NULL)
			|| pthread_mutex_init(&data->philosophers[i - 1]->eat_finished_lock,
				NULL)
			|| pthread_mutex_init(
				&data->philosophers[i - 1]->eat_timestamp_lock, NULL))
			return (MUTEX_FAIL);
	}
	return (SUCCESS);
}

/**
 * @brief Initialize the main struct s_common_data that will
 * store all necessary data for the philo program.
 * 
 * @param data the main data struct s_common_data.
 * @param ac argument count.
 * @param av argument vector.
 * @return t_err - 0 for success or an error code defined in t_err.
 */
t_err	init_memory(t_common_data **data, int ac, char **av)
{
	*data = malloc(sizeof(t_common_data));
	if (!*data)
		return (MALLOC_FAIL);
	memset(*data, 0, sizeof(t_common_data));
	(*data)->number_of_philosophers = my_atoi(av[1]);
	(*data)->time_to_die = my_atoi(av[2]);
	(*data)->time_to_eat = my_atoi(av[3]);
	(*data)->time_to_sleep = my_atoi(av[4]);
	if (ac == 6)
		(*data)->number_of_times_each_philosopher_must_eat = my_atoi(av[5]);
	else
		(*data)->number_of_times_each_philosopher_must_eat = -1;
	(*data)->is_finished = FALSE;
	if (init_philosophers(*data) != SUCCESS || init_mutexes(*data) != SUCCESS)
	{
		free_memory(*data);
		return (FAIL);
	}
	return (SUCCESS);
}
