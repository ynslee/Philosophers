/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:41:47 by yoonslee          #+#    #+#             */
/*   Updated: 2023/07/31 14:56:23 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *info)
{
	int	i;

	i = -1;
	info->philo = malloc(sizeof(t_philo) * info->p_number);
	if (!info->philo)
		ft_putstr_fd("malloc error in initialising philosopher");
	while (++i < info->p_number)
	{
		info->philo[i].id = i + 1;
		info->philo.
	}
}