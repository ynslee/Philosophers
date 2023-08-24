/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:19:29 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/24 12:37:17 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error	philo_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo_is_dead(philo->data))
	{
		pthread_mutex_unlock(&philo->data->print);
		return (ERROR);
	}
	printf("%lld %d %s\n", timestamp(philo->data->start_time), philo->p_id, str);
	pthread_mutex_unlock(&philo->data->print);
	return (SUCCESS);
}
