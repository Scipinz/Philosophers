/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 12:48:29 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/14 12:48:57 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int			id;
	// pthread_t	thread;

	long		time_eaten;
	long		meals_eaten;
	void		*left_fork;
	void		*right_fork;
}	t_philo;

typedef struct s_data
{
	int				amount_philo;

	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	bool			meals;
	int				amount_meals;

	bool			sim_active;
	t_philo			*philo;
	// pthread_mutex_t	*fork;
	// pthread_mutex_t	print_lock;
	// pthread_mutex_t	data_lock;
}	t_data;

#endif
