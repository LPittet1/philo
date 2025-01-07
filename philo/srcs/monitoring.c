/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:05:45 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/07 13:26:26 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_dead(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&philo->meal_mutex);
	if (get_time(data->start) - philo->last_meal > philo->data->time_to_die)
	{
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

int	eaten_enough(t_philo **philos, t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&philos[i]->meal_mutex);
		if (philos[i]->num_eat < data->num_to_eat)
		{
			pthread_mutex_unlock(&philos[i]->meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philos[i]->meal_mutex);
		i++;
	}
	return (1);
}

void	*monitoring(void *d)
{
	int 	i;
	t_data *data;

	printf("Moni start\n");
	data = (t_data *)d;
	while (!data->fininsh_sim)
	{
		i = 0;
		while(i < data->num_philos)
		{
			if (is_dead(data->philos[i], data)
				|| (data->num_to_eat < 0 && eaten_enough(data->philos, data)))
			{
				pthread_mutex_lock(&data->end_mutex);
				data->fininsh_sim = 1;
				pthread_mutex_unlock(&data->end_mutex);
			}
			i++;
		}
	}
	return (NULL);
}
