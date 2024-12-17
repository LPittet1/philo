/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:44:27 by lpittet           #+#    #+#             */
/*   Updated: 2024/12/17 11:15:03 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *nptr)
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
