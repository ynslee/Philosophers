/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:46:18 by yoonslee          #+#    #+#             */
/*   Updated: 2023/07/21 15:29:44 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_data *info)
{
	if (info->p_number < 1 || info->p_number > 200)
	{
		printf("Not the right number of philosopher\n");
		return (1);
	}
	if (info->die_time <= 0)
	{
		printf("Time to die input is not correct\n");
		return (1);
	}
	if (info->eat_time <= 0)
	{
		printf("Time to eat input is not correct\n");
		return (1);
	}
	if (info->sleep_time <= 0)
	{
		printf("Time to sleep input is not correct\n");
		return (1);
	}
	return (0);
}
