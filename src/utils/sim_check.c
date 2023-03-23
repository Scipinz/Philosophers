/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 16:36:20 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/22 14:04:08 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	death_check(t_data *data)
{
	size_t	i;
	long	cur_time;

	i = 0;
	cur_time = gettime();
	while (data->amount_philo > i)
	{
		pthread_mutex_lock(&data->lock_data);
		if (cur_time - data->philo[i].time_eaten > data->time_to_die)
		{
			pthread_mutex_unlock(&data->lock_data);
			pthread_mutex_lock(&data->lock_data);
			data->active_sim = false;
			pthread_mutex_unlock(&data->lock_data);
			print_state(data, &data->philo[i], DIED, true);
			return (true);
		}
		pthread_mutex_unlock(&data->lock_data);
		i++;
	}
	return (false);
}

static bool	meal_check(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->amount_philo > i)
	{
		pthread_mutex_lock(&data->lock_data);
		if (data->philo[i].meals_eaten < data->amount_meals)
		{
			pthread_mutex_unlock(&data->lock_data);
			return (false);
		}
		pthread_mutex_unlock(&data->lock_data);
		i++;
	}
	pthread_mutex_lock(&data->lock_data);
	data->active_sim = false;
	pthread_mutex_unlock(&data->lock_data);
	print_state(data, data->philo, FINISHED, true);
	return (true);
}

void	sim_check(t_data *data)
{
	while (true)
	{
		if (data->meals)
			if (meal_check(data))
				return ;
		if (death_check(data))
			return ;
		usleep(10);
	}
}
