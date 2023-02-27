/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 12:47:29 by kblok         #+#    #+#                 */
/*   Updated: 2023/02/14 15:16:43 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate_args(argc, argv))
		return (EXIT_FAILURE);
	if (!init_data(&data, argv))
		return (EXIT_FAILURE);
	if (!sim_exec(&data))
		return (EXIT_FAILURE);
	sim_check(&data);
	p_join(&data, ALL);
	cleanup(&data, ALL);
	return (EXIT_SUCCESS);
}
