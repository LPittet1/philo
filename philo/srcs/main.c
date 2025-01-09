/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:25 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/09 13:47:20 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	alloc(t_data *d,  pthread_mutex_t **f, pthread_t **p_t, t_philo **p)
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
	if(!p)
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
	//clean
	return (0);
}

//TODO improve fork linking to philos
