/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:44:27 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/07 14:48:49 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t	*init_forks(int num_philos)
{
	pthread_mutex_t	*forks;

	forks = malloc((num_philos) * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	while (num_philos)
	{
		pthread_mutex_init(&forks[num_philos - 1], NULL);
		num_philos--;
	}
	return (forks);
}

void	init_philos(int num, t_data *data, pthread_mutex_t *forks)
{
	int				i;

	i = 1;
	data->philos = malloc(sizeof(t_philo *) * (num + 1));
	if (!data->philos)
		exit(1);
	while (i <= num)
	{
		data->philos[i - 1] = malloc(sizeof(t_philo));
		if (!data->philos[i -1])
			exit(1);
		data->philos[i - 1]->id = i;
		data->philos[i - 1]->data = data;
		data->philos[i - 1]->left_fork = &forks[i - 1];
		if (i == 1)
			data->philos[i - 1]->right_fork = &forks[num - 1];
		else
			data->philos[i - 1]->right_fork = &forks[i - 2];
		pthread_mutex_init(&data->philos[i - 1]->meal_mutex, NULL);
		data->philos[i - 1]->last_meal = data->start;
		data->philos[i - 1]->num_eat = 0;
		i++;
	}
}

void	start_threads(t_data *data, int num_philos)
{
	int 		i;
	pthread_t 	*thread;

	thread = malloc(sizeof(pthread_t) * data->num_philos + 1);
	pthread_create(&thread[0], NULL, monitoring, data);
	i = 1;
	while (i <= num_philos)
	{
		pthread_create(&thread[i], NULL, routine, data->philos[i - 1]);
		i++;
	}
	i = 0;
	while (i <= num_philos)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}



void print_usage(void)
{
	write(2, "USAGE ./philo number_of_philosophers time_to_die time_to_eat", 61);
	write(2, "time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 59);
}
