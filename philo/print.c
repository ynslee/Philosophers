/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:19:29 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/23 13:54:07 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error	philo_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->meals_eaten_lock);
	if (philo->data->death == 1)
	{
		pthread_mutex_unlock(&philo->meals_eaten_lock);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n", timestamp(philo->data->start_time), philo->p_id, str);
	pthread_mutex_unlock(&philo->data->print);
	return (SUCCESS);
}
