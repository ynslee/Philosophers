/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:19:15 by yoonslee          #+#    #+#             */
/*   Updated: 2023/07/31 14:32:06 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"

# define ARGS_ERROR 1

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				meals_eaten;
	pthread_t		thread;
	t_data			*data;
}				t_philo;

typedef struct s_data
{
	int				p_number;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				prepared_meals;
	int				death;
	long long		start_time;
	long long		last_meal_eaten;
	long long		eaten_previous;
	int				meals_eaten;
	pthread_mutex_t	eating;
	pthread_mutex_t	print;
	t_philo			*philo;
}			t_data;

/*args_check.c*/
int			init_data(t_data *info, char **argv);
long long	get_time(void);

/*utils.c*/
int			ft_atoi(const char *str);


#endif