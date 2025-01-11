/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:44:27 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/11 11:19:59 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_threads(pthread_t *p_t, pthread_t *m_t, t_philo *philos)
{
	int	i;

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
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_join(p_t[i], NULL);
		i++;
	}
	pthread_join(*m_t, NULL);
}

void	print_action(char *action, t_philo *philo)
{
	long unsigned	time;
	int				state;

	time = get_time_abs() - philo->start;
	pthread_mutex_lock(&philo->data->end_mutex);
	state = philo->data->fininsh_sim;
	pthread_mutex_unlock(&philo->data->end_mutex);
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!state)
		printf("%lu %i %s\n", time, philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	clean(t_philo *p, t_data *d, pthread_mutex_t *f, pthread_t *t)
{
	int	i;

	i = 0;
	while (i < d->num_philos)
	{
		pthread_mutex_destroy(&f[i]);
		pthread_mutex_destroy(&p[i].meal_mutex);
		i++;
	}
	free(f);
	free(p);
	free(t);
	pthread_mutex_destroy(&d->end_mutex);
	pthread_mutex_destroy(&d->print_mutex);
}
