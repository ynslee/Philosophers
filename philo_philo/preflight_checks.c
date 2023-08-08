/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preflight_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:45:20 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/28 16:42:10 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks that the argument count is correct, prints error message
 * if necessary.
 * @param ac argument count.
 * @return t_err - success or fail.
 */
static t_err	check_argc(int ac)
{
	if (ac >= 5 && ac <= 6)
		return (SUCCESS);
	printf("Incorrect number of arguments!\n");
	printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (FAIL);
}

/**
 * @brief Checks the number of philosophers is at least 1, and less than
 * an arbitrary value. 200 philosophers is the maximum to be evaluated.
 * @param number_of_philosophers_arg the argument string for
 * number_of_philosophers.
 * @return t_err - success or fail.
 */
static t_err	check_number_of_philosophers(char *number_of_philosophers_arg)
{
	int	philo_count;

	philo_count = my_atoi(number_of_philosophers_arg);
	if (philo_count > 0 && philo_count <= MAX_PHILOSOPHER_COUNT)
		return (SUCCESS);
	printf("Number of philosophers (%s) is not between 1 - %i\n",
		number_of_philosophers_arg, MAX_PHILOSOPHER_COUNT);
	return (FAIL);
}

/**
 * @brief Checks that other arguments are positive and in the integer range.
 * 
 * @param ac argument count.
 * @param av argument vector.
 * @return t_err - success or fail.
 */
static t_err	check_other_arguments(int ac, char **av)
{
	int	i;

	i = 2;
	while (i < ac)
	{
		if (my_atoi(av[i]) < 0)
		{
			printf("Not all arguments are in the positive integer range!\n");
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

/**
 * @brief Validates input before running meaningful code.
 * 
 * @param ac argument count.
 * @param av argument vector.
 * @return t_err - success or fail.
 */
t_err	preflight_checks(int ac, char **av)
{
	if (check_argc(ac) != SUCCESS)
		return (FAIL);
	if (check_number_of_philosophers(av[1]) != SUCCESS)
		return (FAIL);
	if (check_other_arguments(ac, av) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}
