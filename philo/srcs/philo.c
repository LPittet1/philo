/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:25 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/11 11:24:50 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	print_usage(void)
{
	write(2, "USAGE ./philo number_of_philosophers", 37);
	write(2, " time_to_die time_to_eat", 25);
	write(2, " time_to_sleep [number_of_times_each_philosopher_must_eat]\n", 60);
}

static int	alloc(t_data *d, pthread_mutex_t **f, pthread_t **p_t, t_philo **p)
{
	*f = init_forks(d->num_philos);
	if (!*f)
		return (0);
	*p_t = malloc(sizeof(pthread_t) * d->num_philos);
	if (!*p_t)
	{
		free(*f);
		return (0);
	}
	*p = init_philos(d, *f);
	if (!p)
	{
		free(*f);
		free(*p_t);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data			data;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		*philo_threads;
	pthread_t		moni_thread;

	if (ac < 5 || ac > 6)
	{
		print_usage();
		return (1);
	}
	parsing(&data, ac, av);
	if (!data.num_philos || !data.time_to_die || !data.time_to_eat
		|| !data.time_to_sleep || !data.num_to_eat)
	{
		print_usage();
		return (1);
	}
	if (alloc(&data, &forks, &philo_threads, &philos) == 0)
		return (1);
	start_threads(philo_threads, &moni_thread, philos);
	join_threads(philo_threads, &moni_thread, data.num_philos);
	clean(philos, &data, forks, philo_threads);
	return (0);
}
