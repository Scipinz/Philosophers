/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 12:47:29 by kblok         #+#    #+#                 */
/*   Updated: 2023/03/22 14:20:11 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_state state;

	if (!validate_args(argc, argv))
		return (EXIT_FAILURE);
	if (!init_data(&data, argv))
		return (EXIT_FAILURE);
	if (!sim_exec(&data))
		return (EXIT_FAILURE);
	sim_check(&data);
	join_threads(&data);
	clean(&data, ALL);
	return (EXIT_SUCCESS);
}
