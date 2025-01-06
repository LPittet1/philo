/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:28 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/06 11:08:29 by lpittet          ###   ########.fr       */
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

void	parsing(t_data *data, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_only_digit(av[i]))
		{
			print_usage();
			exit(1);
		}
		i++;
	}
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->num_to_eat = -1;
	if (ac == 6)
		data->num_to_eat = ft_atoi(av[5]);
	if (data->time_to_die == 0 || data->time_to_eat == 0
		|| data->time_to_sleep == 0 || data->num_to_eat == 0)
	{
		print_usage();
		exit(1);
	}
	init_threads(data, ft_atoi(av[1]));
}
