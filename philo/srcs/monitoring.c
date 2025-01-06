/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:05:45 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/06 13:53:47 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_dead(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&philo->meal);
	if (get_time(data->start) - philo->last_meal > philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal);
	return (0);
}

int	eaten_enough(t_philo **philos, t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&philos[i]->meal);
		if (philos[i]->num_eat < data->num_to_eat)
		{
			pthread_mutex_unlock(&philos[i]->meal);
			return (0);
		}
		pthread_mutex_unlock(&philos[i]->meal);
		i++;
	}
	return (1);
}

int	monitoring(t_data *data)
{
	int i;

	while (1)
	{
		i = 0;
		while(i < data->num_philos)
		{
			if (is_dead(data->philos[i], data))
				break ;
			if (data->num_to_eat && eaten_enough(data->philos, data))
				break ;
			i++;
		}
	}
	return (1);
}