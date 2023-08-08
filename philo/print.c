/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonseonlee <yoonseonlee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:19:29 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/08 15:20:42 by yoonseonlee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error	philo_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n", philo->data->start_time, philo->p_id, str);
	pthread_mutex_unlock(&philo->data->print);
	return (SUCCESS);
}