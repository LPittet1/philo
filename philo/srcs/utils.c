/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:44:27 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/06 11:14:45 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	long	i;
	long	res;

	i = 0;
	res = 0;
	if (nptr[i] == '+')
		i++;
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && nptr[i] <= '\r'))
		i++;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = 10 * res + (nptr[i] - 48);
		i++;
	}
	return (res);
}

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

void	init_philos(int num, t_data **data, pthread_mutex_t *forks)
{
	int	i;

	i = 1;
	while (i < num)
	{
		(*data)->philos[i - 1] = malloc(sizeof(t_philo));
		if (!(*data)->philos[i -1])
			exit(1);
		(*data)->philos[i - 1]->id = i;
		(*data)->philos[i - 1]->data = *data;
		(*data)->philos[i - 1]->left_fork = &forks[i - 1];
		if (i == 1)
			(*data)->philos[i - 1]->right_fork = &forks[num - 1];
		else
			(*data)->philos[i - 1]->right_fork = &forks[i - 2];
		pthread_mutex_init(&(*data)->philos[i - 1]->meal, NULL);
		(*data)->philos[i - 1]->last_meal = (*data)->start;
		(*data)->philos[i - 1]->num_eat = 0;
	}
}

void	init_threads(t_data *data, int num_philos)
{
	int 		i = 1;
	pthread_t 	thread;
	pthread_mutex_t	*forks;
	
	if (!num_philos)
	{
		print_usage();
		exit(1);
	}
	//TODO start_monitoring();
	forks = init_forks(num_philos);
	data->philos = malloc(sizeof(t_philo *) * (num_philos + 1));
	if (!data->philos)
		exit(1);
	init_philos(num_philos, &data, forks);
	while (num_philos)
	{
		data->philos[i - 1] = malloc(sizeof(t_philo));
		if (!data->philos[i - 1])
			exit(1);
		data->philos[i - 1]->id = i;
		pthread_create(&thread, NULL, routine, data->philos[i - 1]);
		pthread_join(thread, NULL);
		i++;
		num_philos--;
	}
}



void print_usage(void)
{
	write(2, "USAGE ./philo number_of_philosophers time_to_die time_to_eat", 61);
	write(2, "time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 59);
}
