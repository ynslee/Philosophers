/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:05:51 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/28 17:21:45 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// for memset
# include <string.h>

// for printf
# include <stdio.h>

// for malloc, free
# include <stdlib.h>

// for write, usleep
# include <unistd.h>

// for gettimeofday
# include <sys/time.h>

// for pthread functions
# include <pthread.h>

// for system limits
# include <limits.h>

# define MAX_PHILOSOPHER_COUNT 200

typedef enum e_err
{
	SUCCESS,
	FAIL,
	MALLOC_FAIL,
	MUTEX_FAIL,
	PRINT_FAIL,
	EAT_FAIL,
	JOIN_FAIL,
	CREATE_THREAD_FAIL,
	INTERRUPTED_FAIL
}	t_err;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_philosopher	t_philosopher;

typedef struct s_common_data
{
	pthread_t		monitor_id;
	pthread_mutex_t	*forks;
	t_philosopher	**philosophers;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	t_bool			is_finished;
	pthread_mutex_t	is_finished_lock;
	pthread_mutex_t	stdout_lock;
	struct timeval	start;
}	t_common_data;

typedef struct s_philosopher
{
	int				philo_id;
	pthread_t		thread_id;
	int				fork_id[2];
	int				eat_count;
	pthread_mutex_t	eat_count_lock;
	t_bool			eat_finished;
	pthread_mutex_t	eat_finished_lock;
	size_t			eat_timestamp;
	pthread_mutex_t	eat_timestamp_lock;
	t_common_data	*common_data;
}					t_philosopher;

int		my_atoi(const char *str);
t_err	preflight_checks(int ac, char **av);
size_t	get_timestamp(struct timeval start);
size_t	us_to_ms(size_t microseconds);
void	free_memory(t_common_data *d);
t_err	init_mutexes(t_common_data *data);
t_err	set_fork_ids(t_common_data *data, int philo_id);
t_err	init_philosophers(t_common_data *data);
t_err	init_memory(t_common_data **data, int ac, char **av);
t_bool	is_philo_finished(t_common_data *d);
t_err	philo_stdout(t_philosopher *p, char *msg);
void	*philo_routine(void *v_p);
t_err	philo_usleep(t_common_data *d, size_t sleep_duration_microseconds);
t_err	philo_sleep(t_philosopher *p);
void	*monitor_routine(void *v_d);
void	init_philosophers_basic_values(t_common_data *d, int philo_idx);

#endif
