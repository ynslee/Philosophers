/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:19:15 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/10 14:31:36 by yoonslee         ###   ########.fr       */
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
	ERROR,
	MALLOC_ERROR,
	MUTEX_ERROR,
	THREAD_ERROR,
	PRINT_ERROR
}	t_error;

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				p_id;
	pthread_t		thread;
	int				l_fork;
	int				r_fork;
	int				meals_eaten;
	long long		eaten_previous;
	int				is_finished;
	pthread_mutex_t	meals_eaten_lock;
	t_data			*data;
}				t_philo;

typedef struct s_data
{
	int				p_numbers;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	int				prepared_meals;
	int				death;
	int				full_philo;
	struct timeval	start_time;
	long long		time;
	long long		last_meal_eaten;
	long long		eaten_previous;
	int				meals_eaten;
	pthread_mutex_t	*fork;
	pthread_mutex_t	monitoring;
	pthread_mutex_t	eating;
	pthread_mutex_t	print;
	pthread_mutex_t	finished;
	pthread_t		monitor;
	t_philo			**philo;
}			t_data;

/*args_check.c*/
t_error		init_data(t_data *info, char **argv);
long long	timestamp(struct timeval time);

/*utils.c*/
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);

/*init.c*/
t_error		init_philo(t_data *info);
t_error		init_mutex(t_data *info);

/*print.c*/
t_error		philo_print(t_philo *philo, char *str);

/*main.c*/
int			main(int argc, char **argv);

/*philo_fest.c*/
void		*philo_fest(void *data);

/*philo.c*/
t_error		create_philos(t_data *info);
t_error		philo_thread_create(t_data *info);

/*monitor.c*/
void		*host_tasks(void *data);

#endif