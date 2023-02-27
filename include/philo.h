/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 12:48:29 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/14 15:18:57 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_clean
{
	FORK,
	DATA,
	STRUCT,
	PRINT,
	ALL
}	t_clean;

typedef struct s_philo
{
	int			id;
	long		time_eaten;
	long		meals_eaten;
	void		*left_fork;
	void		*right_fork;
	
	pthread_t	thread;
}	t_philo;

typedef struct s_data
{
	int				amount_philo;
	int				amount_meals;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	bool			meals;
	bool			sim_active;
	
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_data;
}	t_data;

typedef struct s_wrap
{
	t_data	*w_data;
	t_philo	*w_philo;
}	t_wrap;

#endif
