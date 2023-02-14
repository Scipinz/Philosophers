/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initiate_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 14:17:49 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/14 12:51:23 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_philos(t_data *data)
{
	size_t	i;

	i = 0;
	data->philo = ft_calloc(data->amount_philo, sizeof(t_philo));
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
	return (true);
}
