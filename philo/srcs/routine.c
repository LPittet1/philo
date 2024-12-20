/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:48:39 by lpittet           #+#    #+#             */
/*   Updated: 2024/12/20 15:46:00 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_think(t_philo *philo)
{
	long unsigned	timestamp;

	timestamp = get_timestamp(philo->data->starting_time);
	printf("%lu\t%i is thinking", timestamp, philo->id);
}

void	philo_eat(t_philo *philo)
{
	
}

void	philo_sleep(t_philo *philo)
{
	long unsigned	timestamp;

	timestamp = get_timestamp(philo->data->starting_time);
	printf("%lu\t%i is sleeping", timestamp, philo->id);
	usleep(1000 * philo->data->time_to_sleep);
}

void	*routine(void *p)
{
	t_philo *philo;
	philo = (t_philo *)p;
	printf("%i\n", philo->id);
	return (NULL);
}