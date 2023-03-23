/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 12:48:29 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/23 13:09:37 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// colours
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"

# define INTERVAL 100

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
	bool			active_sim;
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

typedef enum e_state
{
	PICK_UP_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	FINISHED
}	t_state;

typedef enum e_clean
{
	FORK,
	DATA,
	STRUCT,
	PRINT,
	ALL
}	t_clean;

// validate arguments
bool	validate_args(int argc, char **argv);

// sim check
void	sim_check(t_data *data);

// print state
void	print_state(t_data *data, t_philo *philo, t_state state, bool death);

// initiate data
void	assign_args(t_data *data, char **argv);
bool	init_data(t_data *data, char **argv);

// simulation execution
void	*philos(void *arg);
bool	sim_exec(t_data *data);

// get time
long	gettime(void);

// clean
void	clean(t_data *data, t_clean n);

// actions
bool	action_thinking(t_data *data, t_philo *philo);
bool	action_sleeping(t_data *data, t_philo *philo);
bool	pick_up_forks(t_data *data, t_philo *philo);
bool	action_eating(t_data *data, t_philo *philo);

// threads
bool	read_data(pthread_mutex_t *mutex, bool *id);
bool	create_threads(pthread_t *thread, t_wrap *data_wrap);
bool	mutex_init(pthread_mutex_t *mutex);
void	join_threads(t_data *data);

// functions
void	*ft_calloc(size_t count, size_t size);
long	ft_atoi(const char *str);
#endif
