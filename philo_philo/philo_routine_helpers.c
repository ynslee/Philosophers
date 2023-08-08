/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:35:57 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/27 16:48:37 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_philo_finished(t_common_data *d)
{
	t_bool	tmp;

	tmp = FALSE;
	pthread_mutex_lock(&d->is_finished_lock);
	if (d->is_finished == TRUE)
		tmp = TRUE;
	pthread_mutex_unlock(&d->is_finished_lock);
	return (tmp);
}

t_err	philo_stdout(t_philosopher *p, char *msg)
{
	pthread_mutex_lock(&p->common_data->stdout_lock);
	if (is_philo_finished(p->common_data) == TRUE)
	{
		pthread_mutex_unlock(&p->common_data->stdout_lock);
		return (PRINT_FAIL);
	}
	printf("%-8zu %-4i %s\n",
		us_to_ms(get_timestamp(p->common_data->start)), p->philo_id, msg);
	pthread_mutex_unlock(&p->common_data->stdout_lock);
	return (SUCCESS);
}
