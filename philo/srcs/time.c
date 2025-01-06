/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:45 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/06 13:55:30 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long unsigned	get_time_abs(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long unsigned	get_time(long unsigned start)
{
	return (get_time_abs() - start);
}

void	ft_usleep(long unsigned millisecond)
{
	long unsigned	start;

	start = get_time_abs();
	while (get_time_abs() - start < millisecond * 1000)
		usleep(100);
}
