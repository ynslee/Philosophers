/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:04:32 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/28 17:22:43 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_err	join_threads(t_common_data *d)
{
	int		i;
	t_err	ret;

	ret = SUCCESS;
	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (pthread_join(d->philosophers[i]->thread_id, NULL))
		{
			ret = JOIN_FAIL;
		}
		i++;
	}
	if (pthread_join(d->monitor_id, NULL))
		ret = JOIN_FAIL;
	return (ret);
}

t_err	create_threads(t_common_data *d)
{
	int	i;

	gettimeofday(&d->start, NULL);
	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (pthread_create(&d->philosophers[i]->thread_id,
				NULL, &philo_routine, d->philosophers[i]))
		{
			printf("Error: create_threads: philo\n");
			return (CREATE_THREAD_FAIL);
		}
		i++;
	}
	if (pthread_create(&d->monitor_id, NULL, &monitor_routine, d))
	{
		printf("Error: create_threads: monitor\n");
		return (CREATE_THREAD_FAIL);
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_common_data	*data;

	if (preflight_checks(ac, av) != SUCCESS)
		return (1);
	if (init_memory(&data, ac, av) != SUCCESS)
		return (1);
	if (create_threads(data) != SUCCESS)
		printf("Error: create_threads\n");
	if (join_threads(data) != SUCCESS)
		printf("Error: join_threads\n");
	free_memory(data);
	return (0);
}
