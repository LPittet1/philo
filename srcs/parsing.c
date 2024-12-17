/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:28 by lpittet           #+#    #+#             */
/*   Updated: 2024/12/17 11:10:30 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	is_only_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int parsing(t_philo *philo, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_only_digit(av[i]))
		{
			//print usage
			exit(1);
		}
		i++;
	}
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->num_eat = -1;
	if (ac == 6)
		philo->num_eat = ft_atoi(av[5]);
	if (philo->time_to_die == 0 || philo->time_to_eat == 0
		|| philo->time_to_sleep == 0 || philo->num_eat == 0)
	{
		//print_usage
		exit(1);
	}
	return (ft_atoi(av[1]));
}

//TODO init philo struct 