/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:25 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/07 14:34:31 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	pthread_mutex_t	*forks;
	//t_philo			*philos;

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
	forks = init_forks(data.num_philos);
	init_philos(data.num_philos, &data, forks);
	start_threads(&data, data.num_philos);
	//clean
	return (0);
}

//TODO mutex_to_end simu, et adapter routine a ce changement
