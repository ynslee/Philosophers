/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:52:23 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/26 12:39:34 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				neg;

	res = 0;
	neg = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		neg = neg * -1;
	while (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > 2147483647)
		{
			if (neg > 0)
				return (-1);
			else
				return (0);
		}
		str++;
	}
	return ((int)res * neg);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

t_error	sleeping(t_philo *philo)
{
	if (philo_print(philo, "is sleeping"))
		return (ERROR);
	philo_sleep(philo->data, philo->data->sleep_time);
	return (SUCCESS);
}

long long	timestamp(struct timeval start_time)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_sec - start_time.tv_sec) * 1000 \
	+ (current.tv_usec - start_time.tv_usec) / 1000);
}

/**
 * @brief drop the right left fork
 *mutex_unlock for right & left fork
 */
void	drop_the_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->fork[philo->r_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->l_fork]);
}
