/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 15:06:46 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/22 16:52:08 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_start(long duration)
{
	long	start_time;

	start_time = gettime();
	while (gettime() - start_time < duration)
		usleep(INTERVAL);
}

bool	action_thinking(t_data *data, t_philo *philo)
{
	if (!read_data(&data->lock_data, &data->active_sim))
		return (false);
	print_state(data, philo, THINKING, false); 
	return (true);
}

bool	action_sleeping(t_data *data, t_philo *philo)
{
	if (!read_data(&data->lock_data, &data->active_sim))
		return (false);
	print_state(data, philo, SLEEPING, false); 
	action_start(data->time_to_sleep);
	return (true);
}

void	pick_up_forks(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(data, philo, PICK_UP_FORK, false); 
		pthread_mutex_lock(philo->right_fork);
		print_state(data, philo, PICK_UP_FORK, false); 
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_state(data, philo, PICK_UP_FORK, false); 
		pthread_mutex_lock(philo->left_fork);
		print_state(data, philo, PICK_UP_FORK, false); 
	}
}

bool	action_eating(t_data *data, t_philo *philo)
{
	print_state(data, philo, EATING, false);
	philo->time_eaten = gettime();
	action_start(data->time_to_eat);
	if (data->meals > 0)
		philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (true);
}
