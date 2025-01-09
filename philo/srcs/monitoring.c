/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:05:45 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/09 14:54:11 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_dead(t_philo *p)
{
	// printf("last meal %lu\n", p->last_meal - p->data->start);
	// printf("ttd = %lu\n", p->data->time_to_die);
	pthread_mutex_lock(&p->meal_mutex);
	if (p->last_meal - p->data->start > p->data->time_to_die)
	{
		pthread_mutex_unlock(&p->meal_mutex);
		return (p->id);
	}
	pthread_mutex_unlock(&p->meal_mutex);
	return (0);
}

static int	eaten_enough(t_philo **philos)
{
	int	i;

	i = 0;
	while (i < philos[0]->data->num_philos)
	{
		pthread_mutex_lock(&philos[i]->meal_mutex);
		if (philos[i]->num_eat < philos[0]->data->num_to_eat)
		{
			pthread_mutex_unlock(&philos[i]->meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philos[i]->meal_mutex);
		i++;
	}
	return (1);
}

void	*monitoring(void *p)
{
	t_philo *philos;
	int		i;

	philos = (t_philo *)p;

	while (1)
	{
		i = 0;
		while (i < philos[0].data->num_philos)
		{
			if (is_dead(&philos[i]))
			{
				print_action("is dead", &philos[i]);
				pthread_mutex_lock(&philos[0].data->end_mutex);
				philos[0].data->fininsh_sim = 1;
				pthread_mutex_unlock(&philos[0].data->end_mutex);
				return (NULL);
			}
			else if (philos[0].data->num_to_eat > 0 && eaten_enough(&philos))
			{
				pthread_mutex_lock(&philos[0].data->end_mutex);
				philos[0].data->fininsh_sim = 1;
				pthread_mutex_unlock(&philos[0].data->end_mutex);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
