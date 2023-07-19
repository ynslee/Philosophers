/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:19:15 by yoonslee          #+#    #+#             */
/*   Updated: 2023/07/19 18:07:13 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define ARGS_ERROR 1

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				meal_number;
	pthread_t		thread;
}				t_philo;

typedef struct s_all
{
	int				p_number;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meal_number;
	int				death;
	long long		start_time;
	int				eat_check;
	pthread_mutex_t	eating;
	pthread_mutex_t	print;
}			t_all;

/*error_check.c*/
int		check_args(t_all *info);

/*utils.c*/
int		ft_atoi(const char *str);


#endif