/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:57:09 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/28 17:05:02 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_whitespace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

static int	clamp_overflow(size_t input, int sign)
{
	if (input > (size_t)LONG_MAX)
	{
		if (sign == 1)
			return ((int)LONG_MAX);
		else if (input > (size_t)LONG_MAX + 1)
			return ((int)((size_t)LONG_MAX + 1));
	}
	return ((int)input * sign);
}

int	my_atoi(const char *str)
{
	size_t	ans;
	int		sign;

	ans = 0;
	sign = 1;
	if (!*str)
		return (0);
	while (is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ans > LONG_MAX)
			break ;
		ans = ans * 10 + (*str - '0');
		str++;
	}
	return (clamp_overflow(ans, sign));
}
