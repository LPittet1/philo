/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:35 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/11 11:29:39 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	long unsigned	start;
	long unsigned	time_to_die;
	long unsigned	time_to_eat;
	long unsigned	time_to_sleep;
	int				num_to_eat;
	int				num_philos;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	print_mutex;
	int				fininsh_sim;
}	t_data;

typedef struct s_philo
{
	int				id;
	long unsigned	start;
	pthread_mutex_t	meal_mutex;
	int				num_eat;
	long unsigned	last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
}	t_philo;

// init.c
t_philo			*init_philos(t_data *data, pthread_mutex_t *forks);
pthread_mutex_t	*init_forks(int num_philos);

// monitoring.c
void			*monitoring(void *p);

// parsing.c
void			parsing(t_data *data, int ac, char **av);

// routine.c
void			*routine(void *p);

// time.c
long unsigned	get_time_abs(void);
void			ft_usleep(long unsigned millisecond);

// utils.c
void			start_threads(pthread_t *p_t, pthread_t *m_t, t_philo *philos);
void			join_threads(pthread_t *p_t, pthread_t *m_t, int num_philos);
void			print_action(char *action, t_philo *philo);
void			clean(t_philo *p, t_data *d, pthread_mutex_t *f, pthread_t *t);

#endif