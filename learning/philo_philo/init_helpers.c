/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:12:36 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/28 17:22:15 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosophers_basic_values(t_common_data *d, int philo_idx)
{
	memset(d->philosophers[philo_idx], 0, sizeof(t_philosopher));
	d->philosophers[philo_idx]->philo_id = philo_idx + 1;
	d->philosophers[philo_idx]->common_data = d;
	d->philosophers[philo_idx]->eat_finished = 0;
}
