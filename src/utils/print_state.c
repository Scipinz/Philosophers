/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 14:44:54 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/23 15:56:53 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_data *data, t_philo *philo, t_state state, bool death)
{
	if (read_data(&data->lock_data, &data->active_sim) || death)
	{
		pthread_mutex_lock(&data->lock_print);
		printf("%'lu [#%d: "RESET, gettime(), philo->id);
		if (state == SLEEPING)
			printf(MAG "is sleeping\n" RESET);
		else if (state == EATING)
			printf(GRN "is eating\n" RESET);
		else if (state == PICK_UP_FORK)
			printf(YEL "has taken a fork\n" RESET);
		else if (state == THINKING)
			printf(CYN "is thinking\n" RESET);
		else if (state == DIED)
			printf(RED "has died\n" RESET);
		pthread_mutex_unlock(&data->lock_print);
	}
}
