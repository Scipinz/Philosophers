/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 14:53:32 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/22 14:04:31 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	mutex_init(pthread_mutex_t *mutex)
{
	if (!mutex || (pthread_mutex_init(mutex, NULL) != 0))
		return (false);
	return (true);
}

bool	read_data(pthread_mutex_t *mutex, bool *id)
{
	bool	res;

	pthread_mutex_lock(mutex);
	res = *id;
	pthread_mutex_unlock(mutex);
	return (res);
}

bool	create_threads(pthread_t *thread, t_wrap *data_wrap)
{
	if (pthread_create(thread, NULL, philos, (void *)data_wrap) != 0)
		return (false);
	return (true);
}

void	join_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->amount_philo > i)
	{
		pthread_join(data->philo[i]. thread, NULL);
		i++;
	}
}
