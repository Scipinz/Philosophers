/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 14:44:12 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/14 15:21:53 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_data *data, t_clean n)
{
	int	i;

	i = 0;
	if (n == STRUCT)
	{
		free (data->philo);
		free (data->fork);
	}
	if (n >= DATA)
		pthread_mutex_destroy(&data->lock_data);
	if (n >= PRINT)
		pthread_mutex_destroy(&data->lock_print);
	while (n >= FORK && i < data->amount_philo && data->fork)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	free (data->philo);
	free (data->fork);
}
