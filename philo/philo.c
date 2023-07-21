/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:17:21 by yoonslee          #+#    #+#             */
/*   Updated: 2023/07/21 15:32:36 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// memset, printf, malloc, free, write, usleep, gettimeofday, 
// pthread_create, pthread_join, pthread_detach,
// pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock
// These are the allowed function.
// ./philo [number of philo][time to die][time to eat][time to sleep][number of times to eat]

void	check_args_number(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		
	}
}

int	put_info(t_data *info, char **argv)
{
	check_args_number(argv);
	info->p_number = ft_atoi(argv[1]);
	info->die_time = ft_atoi(argv[2]);
	info->eat_time = ft_atoi(argv[3]);
	info->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		info->meal_number = ft_atoi(argv[5]);
	else
		info->meal_number = -1;
	info->death = 0;
	info->start_time = 0;
	info->eat_check = 0;
	if (check_args(info))
		return (1);
	return (0);
}

int	create_philos()


int	main(int argc, char **argv)
{
	t_data	info;

	if (argc != 5 && argc != 6)
	{
		printf("wrong argument number");
		return (0);
	}
	if (put_info(&info, argv))
		error("error in initializing input\n");
	if (create_philos(&info))
		error("error when creating philos!\n");
}
