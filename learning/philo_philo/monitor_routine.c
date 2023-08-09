/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:15:32 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/28 17:08:06 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_philosopher_fed(int *n_of_fed_philosophers, t_common_data *d,
	t_philosopher *p)
{
	t_bool	ret;

	if (d->number_of_times_each_philosopher_must_eat == -1)
		return (FALSE);
	ret = FALSE;
	pthread_mutex_lock(&p->eat_finished_lock);
	if (p->eat_finished == TRUE)
	{
		*n_of_fed_philosophers = *n_of_fed_philosophers + 1;
		ret = TRUE;
	}
	pthread_mutex_unlock(&p->eat_finished_lock);
	return (ret);
}

t_bool	is_philosopher_dead(t_philosopher *p)
{
	t_bool	ret;

	ret = FALSE;
	pthread_mutex_lock(&p->eat_timestamp_lock);
	if (get_timestamp(p->common_data->start) - p->eat_timestamp
		>= (size_t)p->common_data->time_to_die * 1000)
	{
		pthread_mutex_unlock(&p->eat_timestamp_lock);
		philo_stdout(p, "died");
		pthread_mutex_lock(&p->common_data->is_finished_lock);
		p->common_data->is_finished = TRUE;
		pthread_mutex_unlock(&p->common_data->is_finished_lock);
		ret = TRUE;
	}
	else
	{
		pthread_mutex_unlock(&p->eat_timestamp_lock);
	}
	return (ret);
}

void	*monitor_routine(void *v_d)
{
	int				i;
	int				n_of_fed_philosophers;
	t_common_data	*d;

	d = (t_common_data *)v_d;
	while (1)
	{
		usleep(500);
		i = 0;
		n_of_fed_philosophers = 0;
		while (i < d->number_of_philosophers
			&& n_of_fed_philosophers != d->number_of_philosophers)
		{
			if (is_philosopher_fed(&n_of_fed_philosophers,
					d, d->philosophers[i]) == FALSE)
			{
				if (is_philosopher_dead(d->philosophers[i]) == TRUE)
					return (NULL);
			}
			i++;
		}
		if (n_of_fed_philosophers == d->number_of_philosophers)
			return (NULL);
	}
	return (NULL);
}
