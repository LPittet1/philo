/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:48:39 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/09 13:25:03 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_think(t_philo *philo)
{
	print_action("is thinking", philo);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	print_action("has taken a fork", philo);
	print_action("is eating", philo);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time(philo->data->start);
	philo->num_eat++;
	pthread_mutex_unlock(&philo->meal_mutex);
}

void	philo_sleep(t_philo *philo)
{
	print_action("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	*routine(void *p)
{
	t_philo	*philo;

	
	philo = (t_philo *)p;
	if (philo->id % 2)
		usleep(5);
	pthread_mutex_lock(&philo->data->end_mutex);
	while (!philo->data->fininsh_sim)
	{
		pthread_mutex_unlock(&philo->data->end_mutex);
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
		pthread_mutex_lock(&philo->data->end_mutex);
	}
	pthread_mutex_unlock(&philo->data->end_mutex);
	return (NULL);
}
