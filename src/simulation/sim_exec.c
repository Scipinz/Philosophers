/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_exec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 15:12:04 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/22 13:56:02 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philos(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = ((t_wrap *)arg)->w_philo;
	data = ((t_wrap *)arg)->w_data;
	free ((t_wrap *)arg);
	while (read_data(&data->lock_data, &data->active_sim))
	{
		if (!action_eating(data, philo) || \
			!action_thinking(data, philo) || \
			!action_sleeping(data, philo))
			return (NULL);
	}
	return (NULL);
}

static bool	make_threads(t_data *data)
{
	t_wrap	*data_wrap;
	size_t	i;

	i = 0;
	while (data->amount_philo > i)
	{
		data_wrap = malloc(sizeof(t_wrap));
		if (!data_wrap)
			return (false);
		data->philo[i].id = i + 1;
		data->philo[i].time_eaten = gettime();
		data_wrap->w_data = data;
		data_wrap->w_philo = &data->philo[i];
		if (!create_threads(&data->philo[i].thread, data_wrap))
		{
			free (data_wrap);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	sim_exec(t_data *data)
{
	if (!make_threads(data))
	{
		clean(data, PRINT);
		return (false);
	}
	return (true);
}
