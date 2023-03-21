/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 16:36:20 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/21 14:42:32 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	death_check(t_data *data)
{
	size_t	i;
	long	current;

	i = 0;
	current = gettime();
	while (data->amount_philo > i)
	{
		pthread_mutex_lock(&data->lock_data);
		if (current - data->philo[i].time_eaten > data->time_to_die)
		{
			pthread_mutex_unlock(&data->lock_data);
			pthread_mutex_lock(&data->lock_data);
			data->sim_active = false;
			pthread_mutex_unlock(&data->lock_data);
			print_action(data, &data->philo[i], DIED, true);
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
		if (data->amount_meals > data->philo[i].meals_eaten)
		{
			pthread_mutex_unlock(&data->lock_data);
			return (false);
		}
		pthread_mutex_unlock(&data->lock_data);
		i++;
	}
	pthread_mutex_lock(&data->lock_data);
	data->sim_active = false;
	pthread_mutex_unlock(&data->lock_data);
	print_action(data, &data->philo, FINISHED, true);
	return (true);
}

void	sim_check(t_data *data)
{
	while (true)
	{
		if (data->meals)
			if (meal_check(data))
				return ;
		if (death_check)
			return ;
		usleep(10);
	}
}
