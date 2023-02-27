/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 16:36:20 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/27 16:40:11 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	meal_check(t_data *data)
{

}

static bool	death_check(t_data *data)
{

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
