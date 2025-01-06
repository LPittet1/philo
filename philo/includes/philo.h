/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:35 by lpittet           #+#    #+#             */
/*   Updated: 2025/01/06 13:51:52 by lpittet          ###   ########.fr       */
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
	int				start;
	long unsigned	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat;
	int				num_philos;
	struct s_philo	**philos;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	meal;
	int				num_eat;
	long unsigned	last_meal;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data			*data;
}	t_philo;

void			parsing(t_data *data, int ac, char **av);
int				ft_atoi(const char *nptr);
void			init_threads(t_data *data, int num_philos);
void			*routine(void *philo);
void			print_usage(void);
long unsigned	get_time(long unsigned start);
void			ft_usleep(long unsigned millisecond);

#endif