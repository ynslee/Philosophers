/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:05:56 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/08 14:47:42 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_fest(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo_print(philo, "is thinking") != TRUE)
		return (NULL);
	// if (p->philo_id % 2 == 0)
	// {
	// 	if (philo_usleep(p->common_data,
	// 			p->common_data->time_to_sleep * 1000) != SUCCESS)
	// 		return (NULL);
	// }
	// while (1)
	// {
	// 	if (philo_eat(p) != SUCCESS)
	// 		break ;
	// 	if (philo_sleep(p) != SUCCESS)
	// 		break ;
	// 	if (philo_stdout(p, "is thinking") != SUCCESS)
	// 		break ;
	// }
	// return (NULL);
}
