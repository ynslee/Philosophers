/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:46:18 by yoonslee          #+#    #+#             */
/*   Updated: 2023/07/31 14:37:38 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args_number(char **argv)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	init_data(t_data *info, char **argv)
{
	if (check_args_number(argv))
		return (0);
	info->p_number = ft_atoi(argv[1]);
	if (info->p_number > 200 || info->p_number < 1)
		return (0);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		info->prepared_meals = ft_atoi(argv[5]);
	else
		info->prepared_meals = -1;
	if (info->prepared_meals == 0)
		return (1);
	info->death = 0;
	info->start_time = get_time();
	printf("start time is %lld\n", info->start_time);
	info->meals_eaten = 0;
	info->last_meal_eaten = 0;
	info->eaten_previous = 0;
	return (1);
}
