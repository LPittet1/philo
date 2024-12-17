/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:10:35 by lpittet           #+#    #+#             */
/*   Updated: 2024/12/17 11:10:44 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo
{
	int	name;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_eat;
	int	*right_fork;
	int	*left_fork;
}	t_philo;

int parsing(t_philo *philo, int ac, char **av);
int	ft_atoi(const char *nptr);

#endif