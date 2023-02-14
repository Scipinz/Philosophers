/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:17:49 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/14 15:03:47 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	attach_fork(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo[i].right_fork = &data->fork[data->amount_philo - 1];
	while (i < data->amount_philo)
	{
		data->philo[i].left_fork = &data->fork[i];
		if (i)
			data->philo[i].right_fork = &data->fork[i - 1];
		i++;
	}
}

static bool	init_philos(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo = ft_calloc(data->amount_philo, sizeof(t_philo));
	if (!data->philo)
		return (false);
	data->fork = ft_calloc(data->amount_philo, sizeof(pthread_mutex_t));
	if (!data->fork)
	{
		free (data->philo);
		return (false);
	}
	while (i < data->amount_philo)
	{
		if (!p_mutex_init(&data->fork[i]))
		{
			free (data->philo);
			free (data->fork);
			return (false);
		}
		if (data->meals)
			data->philo[i].meals_eaten = 0;
		i++;
	}
	return (true);
}

void	assign_args(t_data *data, char **argv)
{
	data->amount_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->amount_meals = ft_atoi(argv[5]);
}

bool	init_data(t_data *data, char **argv)
{
	assign_args(data, argv);
	if (!init_philos(data))
		return (false);
	if (!p_mutex_init(&data->lock_data))
	{
		clean(data, DATA);
		return (false);
	}
	if (!p_mutex_init(&data->lock_print))
	{
		clean(data, PRINT);
		return (false);
	}
	attach_fork(data);
	return (true);
}
