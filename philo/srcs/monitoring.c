/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:05:45 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/11 11:27:13 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_dead(t_philo *p)
{
	pthread_mutex_lock(&p->meal_mutex);
	if (get_time_abs() - p->last_meal > p->data->time_to_die)
	{
		pthread_mutex_unlock(&p->meal_mutex);
		return (p->id);
	}
	pthread_mutex_unlock(&p->meal_mutex);
	return (0);
}

static int	eaten_enough(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].data->num_philos)
	{
		pthread_mutex_lock(&philos[i].meal_mutex);
		if (philos[i].num_eat < philos[0].data->num_to_eat)
		{
			pthread_mutex_unlock(&philos[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philos[i].meal_mutex);
		i++;
	}
	return (1);
}

static void	end(t_data *data)
{
	pthread_mutex_lock(&data->end_mutex);
	data->fininsh_sim = 1;
	pthread_mutex_unlock(&data->end_mutex);
}

void	*monitoring(void *p)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)p;
	while (1)
	{
		i = 0;
		while (i < philos[0].data->num_philos)
		{
			if (is_dead(&philos[i]))
			{
				print_action("died", &philos[i]);
				end(philos[0].data);
				return (NULL);
			}
			else if (philos[0].data->num_to_eat > 0 && eaten_enough(philos))
			{
				end(philos[0].data);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
