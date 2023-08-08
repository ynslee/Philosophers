/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonseonlee <yoonseonlee@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:05:56 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/08 15:34:55 by yoonseonlee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_fest(void *data)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)data;
	if (philo_print(philo, "is thinking"))
		return (NULL);
	if (philo->p_id % 2 == 0)
	{
		while ()
	}
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
