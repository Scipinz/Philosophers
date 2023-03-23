/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_time.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 16:59:48 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/21 16:42:58 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec) * 1000) + ((time.tv_usec) / 1000));
}
