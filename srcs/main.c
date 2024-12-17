/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/12/17 11:14:10 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo philo;
	int		num_philo;

	if (ac < 5 || ac > 6)
	{
		// print usage
		return (1);
	}
	num_philo = parsing(&philo, ac, av);
	printf("num philo = %i\n", num_philo);
	if (!num_philo)
	{
		//print_usage
		return (1);
	}
	return (0);
}
