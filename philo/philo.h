/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:19:15 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/08 13:02:30 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> //memset
# include <stdlib.h> //malloc, free
# include <stdio.h> //printf
# include <unistd.h> //write, usleep
# include <pthread.h> //pthreadfunction
# include <sys/time.h> //gettimeofday
# include "libft/libft.h"

# define ARGS_ERROR 1

typedef enum e_error
{
	SUCCESS,
	FAIL,
	MALLOC_ERROR,
	MUTEX_ERROR,
	THREAD_ERROR
}	t_error;


typedef struct s_data	t_data;

typedef struct s_philo
{
	int				p_id;
	pthread_t		thread;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				meals_eaten;
	int				last_meal;
	pthread_mutex_t	meals_eaten_lock;
	t_data			*data;
}				t_philo;

typedef struct s_data
{
	int				p_numbers;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				prepared_meals;
	int				death;
	int				finished;
	long long		start_time;
	long long		last_meal_eaten;
	long long		eaten_previous;
	int				meals_eaten;
	pthread_mutex_t	eating;
	pthread_mutex_t	print;
	pthread_mutex_t	finished;
	pthread_t		monitor;
	t_philo			**philo;
}			t_data;

/*args_check.c*/
int			init_data(t_data *info, char **argv);
long long	get_time(void);

/*utils.c*/
int			ft_atoi(const char *str);

/*init.c*/
t_error		init_philo(t_data *info);


#endif