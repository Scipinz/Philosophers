/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 12:48:29 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/13 12:31:30 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
    int     philo_amount;

    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    bool    meals;
    int     amount_meals;

    bool    sim_active;
}   t_data;

#endif
