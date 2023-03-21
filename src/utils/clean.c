/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 14:44:12 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/20 14:24:33 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_data *data, t_clean n)
{
	int	i;

	i = 0;
	if (n == STRUCT)
	{
		free (data->fork);
		free (data->philo);
	}
	if (n >= DATA)
		pthread_mutex_destroy(&data->lock_data);
	if (n >= PRINT)
		pthread_mutex_destroy(&data->lock_print);
	while (n >= FORK && data->amount_philo > i && data->fork)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	free (data->fork);
	free (data->philo);
}
