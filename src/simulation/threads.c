/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/14 14:53:32 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/14 14:56:53 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    p_mutex_init(pthread_mutex_t *mutex)
{
    if (!mutex || (pthread_mutex_init(mutex, NULL) != 0))
        return (false);
    return (true);
}