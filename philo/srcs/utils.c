/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:44:27 by lpittet           #+#    #+#             */
/*   Updated: 2024/12/20 15:39:55 by lpittet          ###   ########.fr       */
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
// void	init_fork(pthread_mutex_t **fork, int num_philos)
// {
		
// }

void	init_threads(t_data *data, int num_philos)
{
	int 		i = 1;
	pthread_t 	thread;
	//pthread_mutex_t	*forks;
	
	if (!num_philos)
	{
		print_usage();
		exit(1);
	}
	//TODO start_monitoring();
	//TODO forks = init_forks(num_philos);
	data->philos = malloc(sizeof(t_philo *) * (num_philos + 1));
	if (!data->philos)
		exit(1);
	//TODO data->philos = init_philos(num_philos, data);
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
