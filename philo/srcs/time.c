/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:45 by lpittet           #+#    #+#             */
/*   Updated: 2024/12/16 14:46:36 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long unsigned get_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long unsigned get_timestamp(long unsigned start)
{
	return (get_time() - start);
}

void ft_usleep(long unsigned millisecond)
{
	long unsigned start;
	
	start = get_time();
	while (get_time() - start < millisecond)
		usleep(100);
}