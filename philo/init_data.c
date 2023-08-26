/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:46:18 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/26 12:17:21 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_error	check_args_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57) || argv[i][j] != '+')
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

t_error	init_data(t_data *info, char **argv)
{
	if (!check_args_number(argv))
		return (ERROR);
	info->p_numbers = ft_atoi(argv[1]);
	if (info->p_numbers > 200 || info->p_numbers < 1)
		return (ERROR);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		info->prepared_meals = ft_atoi(argv[5]);
	else
		info->prepared_meals = -1;
	if (info->prepared_meals == 0)
		return (ERROR);
	info->death = 0;
	info->meals_eaten = 0;
	info->last_meal_eaten = 0;
	info->full_philo = 0;
	return (SUCCESS);
}
