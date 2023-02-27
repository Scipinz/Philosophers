/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_exec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 15:12:04 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/27 16:37:32 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*sims(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	data = ((t_wrap *)arg)->w_data;
	philo = ((t_wrap *)arg)->w_philo;
	free ((t_wrap *)arg);
	while (read_data(&data->lock_data, &data->sim_active))
	{
		if (!philo_eat(data, philo) || \
			!philo_sleep(data, philo) || \
			!philo_think(data, philo))
			return (NULL);
	}
	return (NULL);
}

static bool	make_threads(t_data *data)
{
	size_t	i;
	t_wrap	*data_wrap;

	i = 0;
	while (i < data->amount_philo)
	{
		data_wrap = malloc(sizeof(t_wrap));
		if (!data_wrap)
			return (false);
		data->philo[i].id = i + 1;
		data->philo[i].time_eaten = gettime();
		data_wrap->w_data = data;
		data_wrap->w_philo = &data->philo[i];
		if (!p_create(&data->philo[i].thread, data_wrap))
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
		cleaup(data, PRINT);
		return (false);
	}
	return (true);
}
