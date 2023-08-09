/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:17:03 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/09 20:23:16 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*host_tasks(void *data)
{
	//check if there is any death happening
	//if it happens, make everyone unlock their mutexes and return
	//or if the eaing has been finished, also return
}