/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:28 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/11 11:24:00 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_atoi(const char *nptr)
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
			return ;
		i++;
	}
	data->start = get_time_abs();
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->num_philos = ft_atoi(av[1]);
	data->num_to_eat = -1;
	if (ac == 6)
		data->num_to_eat = ft_atoi(av[5]);
	data->fininsh_sim = 0;
	pthread_mutex_init(&data->end_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
}
