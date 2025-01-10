/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:44:27 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/10 17:19:57 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t	*init_forks(int num_philos)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc((num_philos) * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*init_philos(t_data *data, pthread_mutex_t *forks)
{
	int 	i;
	t_philo	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!philos)
		return (NULL);
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].right_fork = &forks[i];
		philos[i].left_fork = &forks[(i + 1) % data->num_philos];
		philos[i].data = data;
		philos[i].last_meal = data->start;
		philos[i].start = data->start;
		philos[i].num_eat = 0;
		pthread_mutex_init(&philos[i].meal_mutex, NULL);
		i++;
	}
	return (philos);
}

void	start_threads(pthread_t *p_t, pthread_t *m_t, t_philo *philos)
{
	int i;

	i = 0;
	pthread_create(m_t, NULL, monitoring, philos);
	while (i < philos[0].data->num_philos)
	{
		pthread_create(&p_t[i], NULL, routine, &philos[i]);
		i++;
	}
}

void	join_threads(pthread_t *p_t, pthread_t *m_t, int num_philos)
{
	int i;

	i = 0;
	while (i < num_philos)
	{
		pthread_join(p_t[i], NULL);
		i++;
	}
	pthread_join(*m_t, NULL);
}

void print_action(char *action, t_philo *philo)
{
	long unsigned	time;
	int 			state;

	time = get_time_abs() - philo->start;
	pthread_mutex_lock(&philo->data->end_mutex);
	state = philo->data->fininsh_sim;
	pthread_mutex_unlock(&philo->data->end_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!state)
		printf("%lu %i %s\n", time, philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	clean_all(t_philo **philo, t_data *data, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&philo[i]->meal_mutex);
		i++;
	}
	free(forks);
	free(*philo);
	pthread_mutex_destroy(&data->end_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}