/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:25 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/06 16:43:39 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		print_usage();
		return (1);
	}
	parsing(&data, ac, av);
	//init_philos
	//start_threads
	//clean
	return (0);
}

//TODO mutex_to_end simu, et adapter routine a ce changement
